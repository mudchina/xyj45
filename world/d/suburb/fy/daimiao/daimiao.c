//mac's daimiao.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","岱庙坊");
  set("long",@LONG
这是一座巨型石坊，以此向北便是岱庙。岱庙又称东岳庙，泰山庙，泰庙
是历代君王封禅泰山时举行大典的地方。
LONG
  );
  set("exits",([
         "north":__DIR__"zhengyan.c",
         "south":__DIR__"yaocan.c",
               ]));
        set("objects", ([
                __DIR__"npc/yin" : 1,
       ]) );

   
  setup();
  replace_program(ROOM);
}
