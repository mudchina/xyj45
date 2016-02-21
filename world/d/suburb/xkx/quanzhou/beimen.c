// Room: /d/quanzhou/beimen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "泉州北门");
	set("long", @LONG
这里是南方第一港泉州的北门。出此门向北可抵中原。
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad5",
                "south" : __DIR__"zhongxin",
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

