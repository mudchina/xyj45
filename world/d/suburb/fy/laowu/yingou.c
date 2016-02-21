
inherit ROOM;

void create()
{
        set("short", "银钩赌坊分店");
        set("long", @LONG
门也不宽，银钩在灯火下闪闪发光。推开门，从刺骨的寒风中走进这温暖如春的
房子，每个人都会深深的吸口气。空气中充满了男人的烟草味，酒味，女人的脂粉香，
刨花油香。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"street2",
  "east" : __DIR__"xiao",
]));
        set("objects", ([
        __DIR__"npc/laoshan" : 1,
	__DIR__"npc/li" : 1,
                        ]) );


        setup();
        replace_program(ROOM);

}

