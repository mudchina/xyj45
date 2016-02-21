// Room: /d/quanzhou/qzroad1.c
// Date: Maay 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
LONG
	);

	set("exits", ([
		"northwest" : "/d/suburb/xkx/taishan/yidao1",
                "south" : __DIR__"qzroad2",
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

