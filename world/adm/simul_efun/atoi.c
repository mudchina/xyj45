// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// atoi.c

int atoi(string str)
{
   int v;

   if( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
   return v;
}
