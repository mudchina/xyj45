// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
	你走在西大街上，感到这里的街面要比别处的干净、整洁。大概因为靠近
衙门、兵营可受保护的缘故，富人们都喜欢住在这里。东边静悄悄地没有几个行人
，西边是西城门通往郊外。南边是一座镖局，北边是一所富丽堂皇的大宅院。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"south" : __DIR__"biaoju",
		"west" : __DIR__"ximen",
		"north" : __DIR__"caizhu",
	]));

	setup();
	replace_program(ROOM);
}

