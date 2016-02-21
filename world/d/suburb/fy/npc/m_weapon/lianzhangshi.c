//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "杖场");
        set("long",
		"这里是玄兵古洞的造杖的地方。四周道也不是十分荒凉，相反还可说有\n"
		"几分景致。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，似乎什么都能被它\n"
		"融化似的。\n"	
        );
        set("exits", ([
                "east" : "/d/suburb/fy/baituo/xiaolu2",
        ]));

	set("objects",([__DIR__"npc/shizhang" :1,]));

        setup();
	replace_program(ROOM);
}
