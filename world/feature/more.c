// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// more.c

#include <ansi.h>

varargs void more(string cmd, string *text, int line, int force)
{
  int i,j;

  switch(cmd) {
  case "":
  case "f":
    for(i=line + 23; line<sizeof(text) && line<i; line++)
     write(text[line] + "\n");
    if( line>=sizeof(text) && !force) return;
    break;
  case "b":
  line = line - 46;
  if(line<-22 && !force) return;
  for(i=line + 23; line < i;line++)
   write(text[line]+"\n");
  break;
   case "q":
    return;
  }
  printf("== 未完继续 " HIY "%d%%" NOR 
   " == (ENTER 继续下一页，q 离开，b 前一页)",
   (line*100/sizeof(text)) );
  input_to("more", text, line);
}

varargs void start_more(string msg, int force)
{
    if(!msg || strlen(msg)<1) // no messages.
   return;
  //11/13/97 try to prevent crash by mon.

  more("", explode(msg, "\n"), 0, force);
}
