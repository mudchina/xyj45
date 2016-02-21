inherit ROOM;
#include <room.h>
void create()
{
        set("short", "石级甬道");
        set("long", @LONG
暗门后面十来级石阶，往下延伸成条甬道，甬道里燃着灯，灯火下又有一道门。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"secret",
  "east" : __DIR__"pianting",
]));
        setup();
//door here
        create_door("north", "精铁门", "south", DOOR_CLOSED);

}
