inherit ROOM;
#include <room.h>
void create()
{
        set("short", "厢房");
        set("long", @LONG
屋小幽雅，正中一张小几，几上有琴，琴上无弦。旁边一圆凳，凳上鸳鸯垫。
屋角木床，床单上大红刺绣，绣的是一对鸳鸯戏水。墙角挂着一幅小篆对联：
		焚琴煮鹤从来有，惜香怜玉几个知。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"corror2",
]));
        set("objects", ([
        __DIR__"npc/chick1" : 1,
                        ]) );


        setup();
        create_door("north", "木雕门", "south", DOOR_CLOSED);

}
