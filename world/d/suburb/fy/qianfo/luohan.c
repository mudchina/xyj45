#include <room.h>
inherit ROOM;
void create()
{
  set("short","罗汉堂");
  set("long",@LONG
罗汉为梵语得道者的意思，共有十六大罗汉，受佛敕，永住此世
，以济度众生。此殿供奉的正是这十六罗汉，左右各八，形态各异，
为妙惟肖。
LONG
  );
  set("exits",([
            "south":__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/bonze9" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
