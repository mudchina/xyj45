
inherit ROOM;

void create()
{
        set("short", "倾城胭脂店");
        set("long", @LONG
这里陈列着各式各样的胭脂，有从京都运来的，也有本地产的。胭脂鲜红似血,
香气扑鼻。每当朝阳初升，阳光照入店内，映在胭脂上，给人一种耀眼的亮红。除
了胭脂这里来卖刨花油，花粉袋。店老板听说就是当年江湖中有名的易容高手。
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind2",
        ]));
        set("objects", ([
                "/d/suburb/fy/fengyun/npc/makeupseller": 1,
		__DIR__"npc/younggirl": 2,
        ]) );
        setup();
        replace_program(ROOM);

}
