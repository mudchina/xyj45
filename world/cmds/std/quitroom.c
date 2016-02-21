// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// xuy
#include <ansi.h>
inherit ROOM;

int do_quit();

void create()
{
   set("short", "");
   set("long", @LONG
LONG
   );

   setup();
}

void init()
{
   if (!wizardp(this_player())){ 
        add_action("do_quit","get");
        call_out("force_quit",1,this_player());
        //use delayed quit to avoid the error message
        //in debug.log due to this_player is destructed
        //before the move() is finished.
        // mon 8/17/97
   }
}

int do_quit()
{
    this_player()->force_me("quit");
    return 1;
}

void force_quit(object me)
{
   if(me) me->force_me("quit");
}

