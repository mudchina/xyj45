//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "炼刀场");
        set("long",
		"这里是玄兵古洞的炼刀场。四处充满了金属的气味，炙热的气浪冲的人\n"
		"不由打了个趔趄。一个皮肤黝黑的小伙正坐在一块石头上休息，手中一个\n"
		"巨大的锤头正不停的来回摆动着。看来这小伙快要睡着了。\n"
        );
        set("exits", ([
                "eastup" : "/d/suburb/fy/xingxiu/tianroad6",
        ]));

	set("objects",([__DIR__"npc/shidao" :1,]));

        setup();
	replace_program(ROOM);
}
