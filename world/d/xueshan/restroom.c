// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//restroom.c

inherit ROOM;

void create ()
{
   set ("short", "休息室");
   set ("long", @LONG

这里是雪山弟子平时休息的地方。屋中央有一张大石桌，上面摆
着一些水果点心。边上还有两个里间。其中靠南的一间门上挂着
一张牌子(paizi)。而墙上则乱七八糟地写满了字。
LONG);

   set("item_desc", (["paizi" : "女弟子卧房，男子严禁入内。\n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"girlroom",
     "north" : __DIR__"boyroom",
     //"west" : __DIR__"restroom",
     "east" : __DIR__"wuchang-w",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/misc/seat" : 2,
     "/d/obj/misc/table" : 1,
     "/d/obj/food/xueli" : 3,
     "/d/obj/food/zongzi" : 1,
   ]));

   set("valid_startroom", 1);

   set("outdoors", "xueshan");

   setup();

   "/obj/board/xueshan_b"->foo();
}

void init()
{
   add_action("do_stand", "stand");
   add_action("do_sit", "sit");
}

int do_sit(string arg)
{     
   object me;
   me=this_player();

   if ( !arg || ((arg != "seat")&&(arg != "table") ))
     return notify_fail("你要坐在什么上面？\n");   
   
   if (this_player()->query_temp("marks/sit"))
     return notify_fail("你已经坐下了。\n");   
      
   if ( arg != "seat")   
     return notify_fail("坐桌子上？太不雅观了吧。\n");
           
   this_player()->set_temp("marks/sit", 1);
   message_vision("$N舒舒服服地在石凳上坐下来，翘起了二郎腿。\n",me);
   return 1;   
}

int do_stand(string arg)
{
   object me;
   me=this_player();

   if (!this_player()->query_temp("marks/sit"))
     return notify_fail("你本来就站着。\n");

   this_player()->set_temp("marks/sit", 0);
   message_vision("$N伸了个懒腰，站了起来。\n", me);
   return 1;
}




