//mac's renan.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","仁安门");
  set("long",@LONG
这是岱庙的第二进大门，进入此门便可以看到万代瞻仰的天贶殿
在远处雄伟的泰山的衬托之下，显得尤其壮观。
LONG
  );
  set("exits",([
         "north":__DIR__"zhengyuan.c",
         "south":__DIR__"peitian.c",
         "east" :__DIR__"dongyu.c",
         "west" :__DIR__"chuxun.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
