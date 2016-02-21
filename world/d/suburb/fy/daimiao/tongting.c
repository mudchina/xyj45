//mac's tongting.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","铜亭铁塔");
  set("long",@LONG
眼前矗立的是一座高两丈的铜铸亭子，亭中为一实心铁塔，塔上
刻有日月星云，山水岩石，寓意光明普照，坚固永生，山海年长的意
思。
LONG
  );
  set("exits",([
         "north":__DIR__"houzai.c",
         "south":__DIR__"houqing.c",
               ]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
