// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//eroad2.c

inherit ROOM;

void create ()
{
   set ("short", "小木屋外");
   set ("long", @LONG

很难想象这些木头是从哪里来的。但是这里的确是一间小木屋。
周围是一道冰制的围墙，也不过半人来高。围墙入口出站着一
位身披白袍，腰跨弯刀的男子。
LONG);

   //set("item_desc", ([" *** " : " *** ", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"xiaomuwu",
     //"north" : __DIR__"icegate",
     "west" : __DIR__"eroad1",
     "east" : __DIR__"eroad3",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/xunshi" : 1,
   ]));


   set("outdoors", "xuesan");

   setup();
}

//void init()
//{
   //add_action("do_jump", "jump");
//}

//int do_jump(string arg)
//{
       
//}

int valid_leave(object me, string dir)
{
   object xunshi;
   if (dir == "south" ) {
     if(objectp(xunshi=present("xunshi", environment(me))) && living(xunshi) )
        return notify_fail("冰谷巡使把你一拦道：公主有令，任何人不得入内打搅！\n");
   }

   return ::valid_leave(me, dir);
}

