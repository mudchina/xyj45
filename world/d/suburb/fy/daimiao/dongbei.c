//mac's dongbei.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","东碑廊");
  set("long",@LONG
此为泰庙大事所记的碑廊，最著名的是唐高宗和武则天于显庆六
年遣道士郭行真到泰山建僬造像时所立的双束碑，或称鸳鸯碑，因碑
体是两块相同条石并立而成，暗喻武后与高宗并驾齐驱，同治天下。
LONG
  );
  set("exits",([
         "west":__DIR__"zhengyuan.c",
               ]));
        set("objects", ([
                __DIR__"npc/tian" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
