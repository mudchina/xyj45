// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
	一条坑坑洼洼的土路，弯弯曲曲的通向山里。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southeast" : __DIR__"hsroad2",
		"north" : __DIR__"sexit",
	]));

	setup();
	replace_program(ROOM);
}

