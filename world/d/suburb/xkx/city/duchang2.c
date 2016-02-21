// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
	这里有四条走廊通向不同的房间。
LONG
	);

	set("exits", ([
		"east" : "/d/obj/inherit/room/eproom",
		"west" : "/d/obj/inherit/room/wproom",
		"south" : "/d/obj/inherit/room/sproom",
		"north" : "/d/obj/inherit/room/nproom",
		"down" : __DIR__"duchang",
	]));

	setup();
	replace_program(ROOM);
}

