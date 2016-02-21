// Room: /d/quanzhou/qzroad2.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
东面是江南名城嘉兴。
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad1",
                "east" : __DIR__"jiaxing",
		"south" : __DIR__"qzroad3",
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

