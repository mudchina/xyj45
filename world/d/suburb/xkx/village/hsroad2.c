// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，南边隐约可见到扬州城的城墙。
	北面一条土路通向山里。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"hsroad1",
		"north" : "/d/suburb/xkx/shaolin/yidao",
		"northwest" : __DIR__"hsroad3",
	]));

	setup();
	replace_program(ROOM);
}

