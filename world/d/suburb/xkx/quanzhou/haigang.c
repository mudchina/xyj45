// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
这里是出海的必经之地，正在施工中。
LONG
	);

	set("exits", ([
                "west" : __DIR__"zhongxin",
	]));

	set("objects", ([
                __DIR__"npc/boy":2,
                __DIR__"npc/girl":1,
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

