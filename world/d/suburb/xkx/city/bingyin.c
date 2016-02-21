// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
	这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，
有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视
着四周。看到你进来，他们全都向你包围了过来，形势看来不太妙。南边有一个
门(men)。
LONG
	);

	set("item_desc", ([
		"men" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));

	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 6,
	]));

	create_door("south", "铁门", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

