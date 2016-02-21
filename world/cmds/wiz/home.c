// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string msg, loc;
   object ridee;

   if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
     return notify_fail("你没有自己的工作室。\n");

   if( stringp(msg = me->query("env/msg_home")) )
     if (msg != "") message_vision(msg + "\n", me);
   loc = user_path(geteuid(me)) + "workroom";
   if (ridee = me->ride())
     ridee->move(loc);
   me->move(loc);   
   return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : home

利用此一指令可直接回到自己的工作室。
如果你有 'msg_home' 这个设定, 则在场的人都会看到那个讯息.
HELP
    );
    return 1;
}
