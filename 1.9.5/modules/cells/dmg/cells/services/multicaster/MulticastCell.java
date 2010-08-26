package dmg.cells.services.multicaster ;

import dmg.cells.nucleus.* ;
import dmg.util.* ;

import java.util.* ;
import java.io.*;

public class MulticastCell extends CellAdapter {
   private CellNucleus _nucleus = null ;
   private Args        _args    = null ;
   private Hashtable   _classHash = new Hashtable() ;
   private Object      _ioLock    = new Object() ;
   private class Client {
      private UOID _uoid = null ;
      private CellPath _path = null ;
      private Client( CellPath path ){ _path = path ; }
      private CellPath getPath(){ return _path ; }
      private UOID getUOID(){ return _uoid ; }
      private void setUOID( UOID uoid ){ _uoid = uoid ; }
      public String toString(){ return "Client"+_path ; }
   }
   private class Entry{
      private String _eventClass   = null ;
      private String _eventName    = null ;
      private Object _serverDetail = null ;
      private Object _serverState  = null ;
      private CellPath _path       = null ;
      private Hashtable _clients   = new Hashtable() ;
      private Entry( String eventClass , String eventName ){
         _eventClass = eventClass ;
         _eventName  = eventName ;
      }
      private void addClient( Client client ){
         _clients.put( client.getPath() , client ) ;
      }
      private void removeClient( CellPath path ){
         _clients.remove( path ) ;
      }
      private Client getClient( CellPath path ){
         return (Client)_clients.get( path ) ;
      }
      private Enumeration clients(){ 
         return ((Hashtable)_clients.clone()).elements() ; 
      }
      private void setSourcePath( CellPath path ){
         _path = path ;
      }
      private CellPath getSourcePath(){
         return _path ;
      }
      private void setServerState( Object serverState ){
         _serverState = serverState ;
      }
      private Object getServerState(){
         return _serverState ;
      }
      private void setServerDetail( Object serverDetail ){
         _serverDetail = serverDetail ;
      }
      private Object getServerDetail(){
         return _serverDetail ;
      }
      public String toString(){
         StringBuffer sb = new StringBuffer() ;
         sb.append( " Server   : "+_eventClass+":"+_eventName+"\n" ) ;
         sb.append( "   Detail : "+
                    (_serverDetail==null?"<none>":
                                         _serverDetail.toString())+"\n");
         sb.append( "   State  : "+
                    (_serverState==null?"<none>":
                                         _serverState.toString())+"\n");
         sb.append( "   Path   : "+
                    (_path==null?"<none>":_path.toString())+"\n");
         Enumeration e = _clients.keys() ;
         for( ; e.hasMoreElements() ; ){
            Object key = e.nextElement() ;
            Object value = _clients.get(key) ;
            sb.append( "      "+key.toString()+"="+value.toString()+"\n");
         }
         return sb.toString() ;
      }
   }
   public MulticastCell( String name , String args )throws Exception {
       super( name , args , false ) ;
       _nucleus = getNucleus() ;
       _args    = getArgs() ;
       
       start() ;
   }
   public synchronized void messageArrived( CellMessage message ){
       Object   obj  = message.getMessageObject() ;
       CellPath path = (CellPath)(message.getSourcePath().clone()) ;
       
       if( obj instanceof NoRouteToCellException ){
          synchronized( _ioLock ){
             NoRouteToCellException nrtc = (NoRouteToCellException)obj ;
             say( "NRTCE arrived : "+nrtc ) ; 
             removeByUOID( nrtc.getUOID() ) ;
             return ;
          }
       }
       if( ! ( obj instanceof MulticastEvent ) )return ;
       MulticastEvent mce = (MulticastEvent)obj ;
       try{
          if( mce instanceof MulticastOpen ){            
              MulticastOpen mco = (MulticastOpen)mce ;
//              path.revert() ;
              openArrived( mco , path ) ;
              mce.isOk(true) ;
          }else if( mce instanceof MulticastClose ){
              MulticastClose mcc = (MulticastClose)mce ;
              closeArrived( mcc ) ;
              mce.isOk(true);
              return ;
          }else if( mce instanceof MulticastRegister ){
              MulticastRegister mcr = (MulticastRegister)mce ;
              registerArrived( mcr , path ) ;
              mce.isOk(true);
          }else if( mce instanceof MulticastUnregister ){
              MulticastUnregister mcu = (MulticastUnregister)mce ;
              unregisterArrived( mcu , path ) ;
              mce.isOk(true);
              return ;
          }else if( mce instanceof MulticastMessage ){
              MulticastMessage mcm = (MulticastMessage)mce ;
              registerMessageArrived( mcm , 
                                      path ,
                                      message ) ;
              return ;
          }else{
              throw new
              IllegalArgumentException("Illegal Command : "+mce ) ;
          }
       }catch(Exception ee ){
          esay(ee) ;
          mce.isOk(false);
          mce.setReplyObject(ee) ;
       }
       message.revertDirection() ;
       try{
          sendMessage(message);
       }catch( Exception e ){
          esay( "Failed to reply : "+e) ;
       }
   }
   private Entry getEntry( String eventClass , String eventName ){
      synchronized( _classHash ){
         Hashtable names = (Hashtable)_classHash.get( eventClass ) ;
         if( names == null )return null ;
         return (Entry)names.get( eventName ) ;
      }
   }
   private void removeEntry( String eventClass , String eventName )
           throws NoSuchElementException {
      synchronized( _classHash ){
         Hashtable names = (Hashtable)_classHash.get( eventClass ) ;
         if( names == null )
            throw new
            NoSuchElementException("Class not found : "+eventClass ) ;       
         Object obj = names.get( eventName ) ;
         if( obj == null )
            throw new
            NoSuchElementException("Not found : "+eventClass+":"+eventName) ;       
         names.remove( eventName ) ;
      }
   }
   private Entry newEntry( String eventClass , 
                           String eventName ,
                           boolean overwrite    ){
      synchronized( _classHash ){
         Entry entry = getEntry( eventClass , eventName ) ;
         
         if( ( entry != null ) && ! overwrite )
           throw new 
           IllegalArgumentException( "Duplicate entry" );
           
         entry = new Entry( eventClass , eventName ) ;
         Hashtable hash = (Hashtable)_classHash.get( eventClass ) ;
         if( hash == null )_classHash.put( eventClass , hash = new Hashtable() ) ;
         hash.put( eventName , entry ) ;
         return entry ;
      }
   }
   private void registerArrived( MulticastRegister register , CellPath path ) 
           throws Exception {
       String eventClass = register.getEventClass() ;
       String eventName  = register.getEventName() ;
       Entry entry = getEntry( eventClass , eventName  ) ;
       if( entry == null )
          throw new
          NoSuchElementException("Not found : "+eventClass+":"+eventName) ;
       path.revert() ;
       entry.addClient(new Client(path)) ;
       register.setServerInfo( entry.getServerDetail() , entry.getServerState() ) ;     
   }
   private void unregisterArrived( MulticastUnregister register , CellPath path ) 
           throws Exception {
       String eventClass = register.getEventClass() ;
       String eventName  = register.getEventName() ;
       Entry entry = getEntry( eventClass , eventName  ) ;
       if( entry == null )return ;
       path.revert() ;
       entry.removeClient(path) ;      
   }
   private void registerMessageArrived( 
                  MulticastMessage message , 
                  CellPath path ,
                  CellMessage  originalMessage ) 
           throws Exception {
       String eventClass = message.getEventClass() ;
       String eventName  = message.getEventName() ;
       Object info       = message.getMessage() ;
       Entry entry = getEntry( eventClass , eventName ) ;
       if( entry == null )
          throw new
          NoSuchElementException("Not found : "+eventClass+":"+eventName) ;
       entry.setServerState(info);
       
       CellPath serverPath = entry.getSourcePath() ;
       say( "message Path : "+path+"; serverPath : "+serverPath ) ;
       if( path.equals( serverPath ) ){
          Enumeration clients = entry.clients() ;  
          for( ; clients.hasMoreElements() ; ){
             Client  client = (Client)clients.nextElement() ;
             CellPath outPath  = client.getPath() ;
             try{
                say( "Distributing to "+outPath ) ;
                synchronized( _ioLock ){
                    CellMessage msg = new CellMessage( outPath , message ) ;
                    sendMessage( msg ) ;
                    client.setUOID( msg.getUOID() ) ;
                }
             }catch(NoRouteToCellException nrtce ){
                esay( "remove enforced for client "+path ) ;
                entry.removeClient( path ) ;
             }catch(Throwable t ){
                esay(t) ;
             }

          }
       }else{
          say( "Message from client "+path ) ;
          serverPath = (CellPath)serverPath.clone() ;
          serverPath.revert() ;
          originalMessage.getDestinationPath().add( serverPath ) ;
          originalMessage.nextDestination() ;
          try{
             sendMessage( originalMessage ) ;
          }catch( NoRouteToCellException ee ){
             esay(ee) ;
          }catch( Exception eee ){
             esay(eee);
          }
       }    
   }
   private void openArrived( MulticastOpen open , CellPath path ) 
           throws Exception {
       Entry entry = newEntry( open.getEventClass() ,
                               open.getEventName() ,
                               open.isOverwrite()      ) ;
       entry.setSourcePath( path ) ;
       entry.setServerDetail( open.getServerDetail() ) ;
       entry.setServerState( open.getServerState() ) ;
   }
   private void closeArrived( MulticastClose close ) throws Exception {
       Entry entry = getEntry( close.getEventClass() , close.getEventName()  ) ;
       if( entry == null )return ;
       removeEntry( close.getEventClass() , close.getEventName()  ) ;
       Enumeration clients = entry.clients() ;  
       for( ; clients.hasMoreElements() ; ){
          Client  client = (Client)clients.nextElement() ;
          CellPath path  = client.getPath() ;
          try{
             say( "Close Distributing to "+path ) ;
             sendMessage( new CellMessage( path , close ) ) ;
          }catch(Throwable t ){
             esay(t) ;
          }      
       }    
   }
   //
   private void removeByUOID( UOID uoid ){
       Enumeration classes = _classHash.elements() ;
       for( ; classes.hasMoreElements() ; ){
           Enumeration instances = 
               ((Hashtable)classes.nextElement()).elements() ;
           for( ; instances.hasMoreElements() ; ){
              Entry entry = (Entry)instances.nextElement() ;
              Enumeration clients = entry.clients() ;
              for( ; clients.hasMoreElements() ; ){
                 Client client = (Client)clients.nextElement() ;
                 UOID u = client.getUOID() ;
                 if( u == null )continue ;
                 if( u.equals( uoid ) ){
                   entry.removeClient( client.getPath() ) ;
                   say( "Removed : "+client ) ;
                   return ;
                 }
              }
           }
       }
   }
   //
   public void getInfo( PrintWriter pw ){
   
       Enumeration classes = _classHash.elements() ;
       for( ; classes.hasMoreElements() ; ){
           Enumeration instances = 
               ((Hashtable)classes.nextElement()).elements() ;
           for( ; instances.hasMoreElements() ; ){
              Entry entry = (Entry)instances.nextElement() ;
              pw.println( entry.toString() ) ;
           }
       }
   }
}
