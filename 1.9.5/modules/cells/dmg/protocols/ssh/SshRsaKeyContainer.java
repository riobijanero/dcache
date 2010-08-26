package dmg.protocols.ssh ;
import  java.io.* ;
import  java.util.*;

public class SshRsaKeyContainer extends Hashtable {


   public SshRsaKeyContainer( InputStream stream )
          throws IOException {
      
       BufferedReader reader = 
          new BufferedReader( new InputStreamReader( stream ) ) ;
       
       String line ;
       while( ( line = reader.readLine() ) != null ){
          try{
             SshRsaKey key = new SshRsaKey( line ) ;
             put( key.getModulus() , key ) ;
          }catch( Exception ee ){
             System.err.println( " Problem : "+ee  ) ;
          } // skip invalid lines
       }
   }
   public SshRsaKey findByModulus( SshRsaKey searchKey ){
      return (SshRsaKey) get( searchKey.getModulus() ) ;
   }
   public static void main( String [] args ){
      if( args.length < 1 ){
        System.err.println( " USAGE : SshRsaKeyContainer <publicKeyFile>");
        System.exit(3);
      }
      try{
        SshRsaKeyContainer 
          container = new SshRsaKeyContainer(
                      new FileInputStream( args[0] ) ) ;
        
        System.out.println( " Container holds "+container.size()+" keys" ) ;
        for( Enumeration e = container.elements() ; e.hasMoreElements() ; ){
            SshRsaKey key = (SshRsaKey)e.nextElement() ;
            System.out.println( "\n"+key  ) ;
        
        }
      
      }catch( Exception e ){
        System.err.println( " problem : "+e );
        System.exit(3);
      }
   }

}
 
