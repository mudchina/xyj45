// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// save.c

int save()
{
  string file;

  if( stringp(file = this_object()->query_save_file()) ) {
   assure_file(file+ __SAVE_EXTENSION__);
   return save_object(file);
  }
  return 0;
}

int restore()
{
  string file;

  if( stringp(file = this_object()->query_save_file()) )
   return restore_object(file);
  return 0;
}
