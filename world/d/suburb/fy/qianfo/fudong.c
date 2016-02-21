//mac's fudong.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","千佛洞");
  set("long",@LONG
千佛山因此洞成名。洞壁上雕满了佛像，加上峭壁上的佛像，已
逾千座。中国禅宗佛教自曹溪慧能后，禅徒只以道相授受，多岩居穴
处，这大约便是禅寺初创时始祖的居室。
LONG
  );
  set("exits",([
         "west" :__DIR__"jinggang.c",
         "north":__DIR__"changlang2.c",
               ]));
          set("objects", ([
                __DIR__"npc/master3" : 1,
       ]) ); 
set("valid_startroom", 1);
  setup();
  replace_program(ROOM);
}
