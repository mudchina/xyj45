// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// securityd.c

#include <login.h>

// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.

private mapping wiz_status;
private mapping wiz_sites;

private string *wiz_levels = ({
   "(player)",
   "(elder)",
   "(immortal)",
   "(apprentice)",
   "(wizard)",
   "(arch)",
   "(admin)"
});

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

private mapping trusted_write = ([
   "/":   ({ "(admin)", "(arch)" }),
   "d":   ({ "(wizard)" }),
   "u":      ({ "(wizard)" }),
//     "cmds/std":    ({ "(wizard)" }),
//     "cmds/usr":    ({ "(wizard)" }),
//tool disabled these 2 lines not long ago, who enabled it without 
//telling any admin? ok, I disabled it again...weiqi
     "daemon/skill":    ({ "(wizard)" }),
     "daemon/class":    ({ "(wizard)" }),
     "daemon/condition":    ({ "(wizard)" }),
     "open":   ({ "(wizard)", "(apprentice)" }),
     "ftp":      ({ "(wizard)", "(apprentice)" }),
   
]);

private mapping exclude_write = ([
   "adm":     ({ "(arch)" }),
   "include/net":   ({ "(arch)" }),
   "data":     ({ "(arch)" }),
   "log":     ({ "(arch)" }),
]);

private mapping exclude_read = ([
   "adm":    ({ "(arch)", "(wizard)", "(apprentice)", "(immortal)" }),
   "log":    ({ "(arch)", "(wizard)", "(apprentice)", "(immortal)" }),
]);

void create()
{
   string *wizlist, wiz_name, wiz_level, wiz_site;
   int i;

   wizlist = explode(read_file(WIZLIST), "\n");
   wiz_status = allocate_mapping(sizeof(wizlist));
   wiz_sites = allocate_mapping(sizeof(wizlist));
   for(i=0; i<sizeof(wizlist); i++) {
     if( wizlist[i][0]=='#' )   continue;
     if( sscanf(wizlist[i], "%s %s %s", wiz_name, wiz_level,
        wiz_site) == 3 )  {
         wiz_status[wiz_name] = wiz_level;
         wiz_sites[wiz_name] = wiz_site;
     }
     else if( sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
     else
     {
        wiz_status[wiz_name] = wiz_level;
        wiz_sites[wiz_name] = "";
     }
   }
}

void add_wiz (string wiz_name, string wiz_level, string wiz_site)
{
    wiz_status[wiz_name] = wiz_level;
    wiz_sites[wiz_name] = wiz_site;
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
   string euid;
   
   if( objectp(ob) ) {
     euid = geteuid(ob);
     if( !euid ) euid = getuid(ob);
   }
   else if( stringp(ob) ) euid = ob;

   if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
   else if( member_array(euid, wiz_levels)!=-1 ) return euid;
   else return "(player)";
}

int match_wiz_site(object ob, string site)
{
    string* line;
   string euid;

   euid = ob->query("id");

   if( undefinedp(wiz_sites[euid]) || wiz_sites[euid] == "" )  return 1;

   line = ({});
   line += ({site});
    if(sizeof(regexp(line, wiz_sites[euid])) == 1 )
     return 1;

   return 0;
}


int get_wiz_level(object ob)
{
   return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
   string uid, *wiz, wizlist;
   int i;

   return 1;

   if( geteuid(previous_object())!= ROOT_UID ) return 0;

   if( userp(ob) )        uid = getuid(ob);
   else if(stringp(ob))   uid = ob;
   else return 0;
   
   if( status == "(player)" )
     map_delete(wiz_status, uid);
   else
     wiz_status[uid] = status;
   wiz = keys(wiz_status);
   for(wizlist = "", i=0; i<sizeof(wiz); i++)
     wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
   rm(WIZLIST);
   write_file(WIZLIST, wizlist);
   log_file( "static/promotion", capitalize(uid)
    + " become a " + status + " on " + ctime(time()) + "\n" );
   return 1;
}

string *get_wizlist() { return keys(wiz_status); }

// valid_read - called by the master object to determine whether if an user
//              is allowed to read on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.                               - tool 

int valid_read(string file, mixed user, string func)
{
   return 1;
}
/*
        string euid, status;
        euid = geteuid(user);
   status = get_status(user);
        log_file("read_files", sprintf("%s(%s) %ss %s.\n",euid,status,func,file));
*/
   

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.                               - Annihilator

int valid_write(string file, mixed user, string func)
{
   string euid, status, *path, dir;
   int i;

   if(file == WIZLIST)   return 0;

   if( !objectp(user) )
     error("TRUST_D->valid_write: Invalid argument type of user.\n");

   if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

   // Let user save their save file
   if( func=="save_object" ) {
     if( (sscanf(base_name(user), "/obj/%*s") ||
          sscanf(base_name(user), "/d/%*s") ||
         sscanf(base_name(user), "/u/tool/obj/%*s"))
     &&   sscanf(file, "/data/%*s")
     &&   ( file == (string)user->query_save_file() ||
               file == (string)user->query_save_file()+".o" ||
               file == (string)user->query_save_file()+".oo.o" ||
          file == ((string)user->query_save_file()+".oo") ))
        return 1;
   }

   // Get the euid and status of the user.
   euid = geteuid(user);
   if( !euid ) return 0;
   status = get_status(user);

   if( euid==ROOT_UID ) return 1;

/*   if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
     return 1; */

   if( sscanf(file, "/u/" + euid + "/%*s") ) {
     log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()),euid,status,func,file));
          return 1; 
        }

   path = explode(file, "/");

   // Check if we are excluded in one of the directories containing the file.
   for(i=sizeof(path)-1; i>=0; i--) {
     dir = implode(path[0..i], "/");
     if( undefinedp(exclude_write[dir]) ) continue;
     if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
     if( member_array(status, exclude_write[dir])!=-1 ) return 0;
   }

   // And then check if we are trusted in one of the directories containing
   // the file.
   if( member_array(euid, trusted_write["/"])!=-1 ) 
   {
        log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
     return 1;
    }
   if( member_array(status, trusted_write["/"])!=-1 )
   {
        log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
     return 1;
    }
   if( path[0] == "u") return 0;
   for(i=sizeof(path)-1; i>=0; i--) {
     dir = implode(path[0..i], "/");
     if( undefinedp(trusted_write[dir]) ) continue;
     if( member_array(euid, trusted_write[dir])!=-1 )
       {
            log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
         return 1;
        }
     if( member_array(status, trusted_write[dir])!=-1 )
       {
            log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
         return 1;
        }
   }

   log_file("FILES", sprintf("[%s] %s(%s) write attempt on %s failed.\n",ctime(time()),euid, status, file));
   return 0;
}

int valid_seteuid( object ob, string uid )
{
   if( uid==0 ) return 1;
   if( uid==getuid(ob) ) return 1;
   if( getuid(ob)==ROOT_UID ) return 1;
   if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
   if( wiz_status[uid] != "(admin)"
   &&   wiz_status[getuid(ob)] == "(admin)" )
     return 1;
   return 0;
}
