// Tie@fengyun
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "石巷尽头");
        set("long", @LONG
石巷的尽头是一堵高墙，墙上有一道窄门．墙角有一狗洞，
一条脏稀稀的小河沟从狗洞中流出．时而不时的，一条条浸满血
水的绷带从狗洞中流出．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone1",
  "north" : __DIR__"sroom",
]));

        set("outdoors", "fengyun");
        setup();
       create_door("north", "窄门", "south", DOOR_CLOSED);

}
