//mac's zhengyan
#include <room.h>
inherit ROOM;
void create()
{
  set("short","正阳门");
  set("long",@LONG
这是一座典型的道观大门，两丈高的青砖围墙隔开了外界的喧嚣
。高大厚实的朱漆大门令人肃然起敬，小屋殿顶下一块大匾：
正阳门。  这就是岱庙的正门。
LONG
  );
  set("exits",([
         "north":__DIR__"peitian.c",
         "south":__DIR__"daimiao.c",
         "west" :__DIR__"jiaolou1.c",
         "east" :__DIR__"jiaolou2.c",
               ]));
        set("objects", ([
                __DIR__"npc/tong" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
