// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "堂屋");
        set("long", @LONG
屋子里潮湿而阴暗，屋子并不十分窄小，但只有一桌，一床，
一凳．更显得四壁箫然，空洞寂寞．也衬得那一盏孤灯更昏黄暗淡．
壁上的积尘未除，屋面上还结着蛛网．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone2",
]));
        set("objects", ([
                __DIR__"npc/master": 1, 
]) );
        set("valid_startroom", 1);

        setup();
       create_door("south", "窄门", "north", DOOR_CLOSED);

}
