//mac's hanbai.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","汉柏院");
  set("long",@LONG
五棵粗大虬曲，枝老苍劲的古柏耸立院中，为汉武帝于元封元年
封禅泰山时所植。
LONG
  );
  set("exits",([
         "west":__DIR__"peitian.c",
               ]));
          set("objects", ([
                __DIR__"npc/ren" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
