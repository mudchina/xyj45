// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//wroad1.c

inherit ROOM;

void create ()
{
   set ("short", "冰崖底");
   set ("long", @LONG

看样子前面是过不去了。往西的路被一块大牌子堵死。牌子上用
醒目的大字写着：“冰谷禁地，擅闯者死！”。
LONG);

   //set("item_desc", ([" *** " : " *** ", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     //"south" : __DIR__"***",
     //"north" : __DIR__"icegate",
     //"west" : __DIR__"binggu",
     "east" : __DIR__"binggu",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/***" : 1,
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

