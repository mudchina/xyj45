
inherit ROOM;

void create()
{
        set("short", "薛记包子");
        set("long", @LONG
店里布置简陋，只有几张方桌和几张长凳。桌面油漆剥落，再也看不出它原来的颜
色。肮脏而残破的碗筷零乱的散落在桌面上。墙角里还有几支脏稀稀的筷子，上面已结
满了蜘蛛网。几只乌蝇在盲目的飞来飞去。。。
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind5",
        ]));
        set("objects", ([
                __DIR__"npc/lifeseller": 1,
        ]) );
        setup();
        replace_program(ROOM);

}
