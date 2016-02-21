#include <room.h>
inherit ROOM;
void create()
{
  set("short","禅房");
  set("long",@LONG
这是一个清净幽雅的小屋，是寺庙弟子悟道修行的地方，墙
上有禅宗六祖的画像，自左向右为：一祖达摩，二祖慧可，三祖僧璨，
四祖道信，五祖弘忍，六祖慧能，透过窗户可以看到门前的梅树。
LONG
  );
  set("exits",([
         "south":__DIR__"changlang4.c",
         "northwest":__DIR__"houshan.c",
         "west" :__DIR__"yezhang.c"
               ]));
          set("objects", ([
		__DIR__"npc/bigmonk" : 1,
       ]) );
   
  setup();
  replace_program(ROOM);
}
