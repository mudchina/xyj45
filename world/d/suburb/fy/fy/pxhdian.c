
inherit ROOM;

void create()
{
        set("short", "飘香花店");
        set("long", @LONG
未入此处，清新的花香已沁人心裨。店中各种名花，玲琅满目，不乏珍奇异种。
来客不分高低贵贱，这里的主人总是笑脸相迎。许多城中的年青人都喜欢在这儿逗留，
盼有一天桃花运会降临在他身上。据这里的老板说，在飘香花店结成的良缘已不可胜
数。
LONG
        );
        set("exits", ([
		"west" : __DIR__"nwind2",
        ]));
        set("objects", ([
                __DIR__"npc/flowerseller": 1,
		__DIR__"npc/youngman": 2,
        ]) );
        setup();
        replace_program(ROOM);

}
