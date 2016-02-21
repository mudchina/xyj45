// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//anshi.c
#include <room.h>
inherit ROOM;

void create ()
{
   set ("short", "亭底暗室");
   set ("long", @LONG

这是牡丹亭底下的一间暗室。黑咕窿咚的什么也看不清。你试着
到处摸了摸(mo)。 
LONG);

   set("exits", 
   ([ //sizeof() == 4
     //"southwest" : __DIR__"juyuan",
     //"north" : __DIR__"southpool",
     "up" : __DIR__"mudanting",
     //"west" : __DIR__"westway6",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"obj/huangtong-key" : 1,
   ]));

   create_door("up", "桌底暗门", "down", DOOR_CLOSED);
   //set("outdoors", "wuzhuang");

   set("no_clean_up", 1);

   setup();
}


void init()
{
   add_action("do_mo", "mo");

   if( query("started") != 1 )
   {
     set("started", 1);
     call_out("generate_key", 54000);//15 hours
   }
}

void generate_key()
{
   remove_call_out("generate_key");
   set("available", 1);
}

int do_mo(string arg)
{
   object me, key;

   me = this_player();

   if( query("available") == 1 )
   {
     set("available", 0);
     key = new(__DIR__"obj/huangtong-key");
     key -> move(this_object());
     message_vision("只听当！地一声，一把黄铜钥匙掉在地上。\n", me);

     remove_call_out("generate_key");
     call_out("generate_key", 54000);//15 hours

     return 1;
   }
   else return notify_fail("你什么也没摸着。\n");
}

int clean_up()
{
   return 0;
}


