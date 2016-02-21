// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武庙");
	set("long", @LONG
	这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭毕敬
地上香礼拜。旁边似乎有一道侧门。
LONG
	);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
//		"up" : __DIR__"wumiao2",
		"northwest": "/d/suburb/xkx/wizard/guest_room",
	]));
        create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

