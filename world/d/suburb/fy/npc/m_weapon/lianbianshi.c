//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "造鞭潭");
        set("long",
		"这里是玄兵古洞的打造钢鞭的地方。处在荒芜人烟的戈壁滩上。居然能有这\n"
		"样一泓漂亮的潭水，真是让人不得不赞叹大自然的鬼斧神工。潭边婷婷站者一位\n"
		"妙龄的少女，手中把玩着一把看似极是锋利的匕首，呆呆的看着深邃的潭水出神。\n"
        );
        set("exits", ([
                "north" : "/d/suburb/fy/xingxiu/nanjiang3",
        ]));

	set("objects",([__DIR__"npc/shibian" :1,]));

        setup();
	replace_program(ROOM);
}
