// 
// 

inherit ROOM;
void create()
{
        set("short", "沉香镇东首");
        set("long", @LONG
这里已经是沉香镇的最东边。从镇里延伸出来的道路在这里渐渐趋于
无影无踪。茅草越来越厚，景色越来越荒凉。再往东就是漫无边际的莽林。
据老一辈的人讲，莽林中既有杀机四伏的陷阱，也隐有武功盖世的奇侠。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/suburb/fy/manglin/edge1",
  "west" : __DIR__"cxe2",
  "south" : __DIR__"dangpu",
]));
        set("objects", ([
        __DIR__"npc/girl": 2,
                        ]) );
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
