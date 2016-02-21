// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// backup.c

int backup()
{
   string file;

   if( stringp(file = this_object()->query_save_file()) ) {
     file = file + ".oo";
     assure_file(file+ __SAVE_EXTENSION__);
     return save_object(file);
   }
   return 0;
}
