// Tie@fengyun
inherit ROOM;
void create()
{
        set("short", "阴暗石巷");
        set("long", @LONG
石巷散发着一种奇怪的霉腐味道．又加杂着一丝血腥．和干净宽敞的
东云大路格格不入．一条又脏又臭的小河沟顺着巷侧缓缓流淌．上面还漂
着染满着黑血的绷带．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/suburb/fy/fy/ecloud1",
  "north" : __DIR__"stone2",
]));
        set("objects", ([
        __DIR__"npc/scavenger" : 1,
			]) );

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
