//mac's tianwang.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","天王殿");
  set("long",@LONG
正面本尊为弥勒化身的布袋和尚坐像，左右为四大天王。四天王
均著天衣：东方天王提头赖吒，左手把刀，右手执矛拄地；西方天王
毗噜博叉，左手执俏，右手把赤索。北方天王毗沙门，左手挚矛驻拄
地，右手擎塔；南方天王毗萨门天，执青色宝剑。。后人称四王为持
国，增长，广目，守护天王。

LONG
  );
  set("exits",([
         "south":__DIR__"dadian.c",
         "north":__DIR__"mile.c",
         "west" :__DIR__"jialan.c",
         "east" :__DIR__"damo.c"
               ]));
        set("objects", ([
                __DIR__"npc/master2" : 1,
		__DIR__"npc/tianwang1" : 1,
                __DIR__"npc/tianwang2" : 1,
                __DIR__"npc/tianwang3" : 1,
                __DIR__"npc/tianwang4" : 1,

		
       ]) );

set("valid_startroom", 1);
  setup();
  replace_program(ROOM);
}
