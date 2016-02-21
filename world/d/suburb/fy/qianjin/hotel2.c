inherit ROOM;
#include <room.h>
void create()
{
        set("short", "厢房");
        set("long", @LONG
此房小而整洁。墙上一小窗，窗外湖色尽收眼低。墙角立一琵琶，上覆红布，似
乎很久没有用过的样子。窗侧对联一幅，言道：
                        易求无价宝，难得有情郎。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"corror3",
]));
        set("objects", ([
        __DIR__"npc/chick2" : 1,
                        ]) );


        setup();
        create_door("south", "木雕门", "north", DOOR_CLOSED);

}
