inherit ROOM;
#include <room.h>
void create()
{
        set("short", "秘室");
        set("long", @LONG
屋子并不大，有一张床，一张桌子。屋子里根本没有窗，四面的墙壁竟赫然全都
是好几寸厚的铁板。桌子上还摆着一个红木盒子和一些酒菜，酒菜居然全部原封不动。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zhoulang",
]));
        set("objects", ([
        __DIR__"npc/blue" : 1,
	__DIR__"npc/fangyuxiang" : 1,
                        ]) );

        setup();
//door here
        create_door("south", "精铁门", "north", DOOR_CLOSED);

}
