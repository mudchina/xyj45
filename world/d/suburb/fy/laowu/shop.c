
inherit ROOM;

void create()
{
        set("short", "草药店");
        set("long", @LONG
屋子里布置得精雅而别致，每一样东西都是精心挑选的，正好摆在最恰当的地方，
炉火烧得正旺，灯也点得很亮。那张铺在椅子上又大又厚的熊皮，温暖得就像是夏日
阳光下的海浪一样。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"street1",
]));
        set("objects", ([
        __DIR__"npc/leng" : 1,
                        ]) );

        setup();
        replace_program(ROOM);

}

