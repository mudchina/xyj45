// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，北边隐约可见到扬州城的城墙。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"wdroad3",
		"north" : __DIR__"wdroad1",
	]));

	setup();
	replace_program(ROOM);
}

