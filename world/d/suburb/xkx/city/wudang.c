// Room: /city/wudang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "武当");
	set("long", @LONG
wu dang
需要更多的说明……
LONG
	);

	set("exits", ([
		"east" : __DIR__"road9",
		"north" : __DIR__"road6",
	]));

	setup();
	replace_program(ROOM);
}

