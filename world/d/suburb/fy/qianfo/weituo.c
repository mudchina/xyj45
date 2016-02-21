// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","韦驮殿");
  set("long",@LONG
韦驮天王为南天王部下八将之一，以勇武著称，现将军身，守护
伽蓝，为禅寺的守护神，双手合十，横宝杵于两腕，两足平立，注视
出入行人。
LONG
  );
  set("exits",([
            "south" :__DIR__"mile.c",
            "north" :__DIR__"guanyin.c",
            "westup":__DIR__"zhonggu.c",
            "eastup":__DIR__"zhonggu2.c"
               ]));
          set("objects", ([
                __DIR__"npc/bonze5" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
