//mac's yuhua.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","雨花道院");
  set("long",@LONG
这是为道士休息，饮食，打坐的处所，俭朴清净，有几个石砌的
桌子，摆放着一些简单的食品，饮料。
LONG
  );
  set("exits",([
         "east":__DIR__"peitian.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
