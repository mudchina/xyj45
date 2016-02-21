//mac's peitan.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","配天门");
  set("long",@LONG
这是岱庙的第一进大门，朱漆大门上的额匾上是御笔：配天门。
东西各有一个院，东院为汉柏院，西院为雨花道院。
LONG
  );
  set("exits",([
         "north":__DIR__"renan.c",
         "south":__DIR__"zhengyan.c",
         "east" :__DIR__"hanbai.c",
         "west" :__DIR__"yuhua.c",
               ]));
          set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
