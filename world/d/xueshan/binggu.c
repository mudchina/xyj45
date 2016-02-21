// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//binggu.c

inherit ROOM;

void create ()
{
   set ("short", "冰谷");
   set ("long", @LONG

眼前的情景把你惊呆了。没想到在这绝无生迹的冰天雪地中还有
这么一块地方。四周望不到顶的冰崖把这里围成了一个方圆近十
里的山谷。紧靠冰崖有大小建筑数十座。而北面的一座宫殿竟似
以寒冰雕就，在冰雪映照下奕奕生光。这座冰宫倚崖而立，修得
雄奇无比，在四周冰崖据高压抑之下仍是显得飞扬欲脱，气势非
凡。
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     //"south" : __DIR__"***",
     "north" : __DIR__"wuchang-s",
     "west" : __DIR__"wroad1",
     "east" : __DIR__"eroad1",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/zhangmen" : 1,
   ]));


   set("outdoors", "xueshan");

   setup();
}



