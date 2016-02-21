// wdroad5.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，四周静悄悄的。西南方向似乎有一条黄土路。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southwest" : __DIR__"wdroad6",
		"north" : __DIR__"wdroad4",
	]));

	setup();
	replace_program(ROOM);
}

