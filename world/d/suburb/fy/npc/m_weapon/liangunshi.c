//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "棍窠");
        set("long",
		"这里是玄兵古洞造棍的地方。周围整齐的堆放着造棍用的原料，一个年轻\n"
		"小伙手里拿着一本玄天棍法，正在仔细的研读着。看到你走了过来，连忙放下\n"
		"手中的书，带着一脸纯真冲你憨憨的一笑，脸不由又红了。\n"
        );
        set("exits", ([
                "east" : "/d/suburb/fy/xueshan/shenghu",
        ]));

	set("objects",([__DIR__"npc/shigun" : 1,]));

        setup();
	replace_program(ROOM);
}
