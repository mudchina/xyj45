// 
// 

inherit ROOM;
void create()
{
        set("short", "沉香镇南街");
        set("long", @LONG
沉香镇的大部分居民都以耕种水稻为生，这里就是他们住的地方。每到
傍晚，农夫们拖着沉重的步伐，带着满身的汗水从田中回来，回到这里一座
座冒着浓浓的炊烟，散发着诱人的稻米香气的家。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter",
  "south" : __DIR__"farmershop",
]));
        set("objects", ([
	__DIR__"npc/farmer": 2,
                        ]) );
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
