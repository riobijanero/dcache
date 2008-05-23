package gplazma.gplazmalite.storageauthzdbService;

import java.util.LinkedHashMap;
import java.util.Iterator;

public class DynamicAuthorizationRecord extends StorageAuthorizationRecord
{

    LinkedHashMap strvals = new LinkedHashMap<String, String>();

    public String subjectDN;
    public String role;

    public DynamicAuthorizationRecord(DynamicAuthorizationRecord dynrecord) {
      this(
      dynrecord.getStringValues().get("$cmd"),
      dynrecord.getStringValues().get("$name"),
      dynrecord.getStringValues().get("$rw"),
      dynrecord.getStringValues().get("$priority"),
      dynrecord.getStringValues().get("$uid"),
      dynrecord.getStringValues().get("$gid"),
      dynrecord.getStringValues().get("$home"),
      dynrecord.getStringValues().get("$root"),
      dynrecord.getStringValues().get("$fsroot"));
    }

    public DynamicAuthorizationRecord(
                          String dynkey,
                          String user,
			              String readonly_str,
                          String priority_str,
                          String uid_str,
                          String gid_str,
                          String home,
                          String root,
                          String fsroot)
    {
      super( user,
             (readonly_str.equals("read-only")) ? true : false,
             tryParse(priority_str, 0),
             tryParse(uid_str, -1),
             tryParse(gid_str, -1),
             home,
             root,
             fsroot);

      strvals.put("$cmd", dynkey);
      strvals.put("$name", user);
      strvals.put("$rw", readonly_str);
      strvals.put("$priority", priority_str);
      strvals.put("$uid", uid_str);
      strvals.put("$gid", gid_str);
      strvals.put("$home", home);
      strvals.put("$root", root);
      strvals.put("$fsroot", fsroot);
    }

    public DynamicAuthorizationRecord()
    {
        this( null, null, "true", "0", "-1", "-1", "", "","");
    }

    public String toString()
    {
      StringBuffer sb = new StringBuffer();
      Iterator keys = strvals.keySet().iterator();
      while (keys.hasNext()) {
        sb.append(' ').append(strvals.get(keys.next()));
      }

      sb.append('\n');
      return sb.toString();
    }

    public String toDetailedString()
    {
      StringBuffer sb = new StringBuffer(" User Authentication Record ");
      Iterator<String> keys = strvals.keySet().iterator();
      while (keys.hasNext()) {
        String key = keys.next();
        sb.append("         " + key + " = " + strvals.get(key) + "\n");
      }

      sb.append('\n');
      return sb.toString();
    }

    public static int tryParse(String int_str, int excepval) {
      try {
        return Integer.parseInt(int_str);
      } catch (Exception e) {
        return excepval;
      }
    }

    public boolean isValid()
    {
      return Username != null;
    }

    public boolean isAnonymous() { return false; }
    public boolean isWeak() {return false; }

    public LinkedHashMap<String, String> getStringValues() {
      return strvals;
    }

}
