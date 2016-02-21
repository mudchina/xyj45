inherit ROOM;
#include <room.h>
void create()
{
        set("short", "金狮镖局大厅");
        set("long", @LONG
大红地毯，珍奇古玩，高悬字画，表明这里的主人不但性情豪爽，广交朋友，
且非大字不识，目中无人之辈。上首一狮皮交椅，左右各明烛闪烁。一古木书案
横于椅前，上面整齐的堆着一卷卷镖局压镖的货票。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"goldlion",
  "east" : __DIR__"ginhall",
  "north" : __DIR__"gmoney",
]));
        set("objects", ([
        __DIR__"npc/gmaster" : 1,
                        ]) );

        setup();
        create_door("north", "铁门", "south", DOOR_CLOSED);

}
