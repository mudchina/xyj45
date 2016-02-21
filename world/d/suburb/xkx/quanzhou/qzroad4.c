// Room: /d/quanzhou/qzroad4.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
北面是江南名城嘉兴。向南则进入福建武夷山区。
LONG
	);

	set("exits", ([
                "north" : __DIR__"jxnanmen",
                "west" : __DIR__"qzroad3",
		"south" : __DIR__"qzroad5",
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

