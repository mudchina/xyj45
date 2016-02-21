#include <room.h>
inherit ROOM;
void create()
{
  set("short","法堂");
  set("long",@LONG
法堂也称讲堂，乃演说佛法集会之地，中间为狮子座，座前为坐
椅，此为法座，座后为象征佛法的狮子图，五排条桌整齐排列在听席
上，左边设钟，右边设小鼓，为上堂说法时鸣之。
LONG
  );
  set("exits",([
            "east":__DIR__"mile.c",
               ]));
        set("objects", ([
                __DIR__"npc/bonze4" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
