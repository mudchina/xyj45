// Room: /d/quanzhou/tieqiang.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "铁枪庙");
	set("long", @LONG
这铁枪庙祀奉的是五代时名将铁枪王彦章。庙旁有座高塔，塔顶
群鸦世代为巢，当地乡民传说铁枪庙的乌鸦是神兵神将，向来不敢侵
犯，以致生养繁殖，越来越多。
LONG
	);

	set("exits", ([
                "west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));

        set("objects", ([
		__DIR__"npc/wuya": 4]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

