// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
	这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台
上摆着一个牌子(paizi)，柜台后坐着唐老板，一双精明的眼睛上上下下打量着你。
LONG
	);
	set("no_beg",1);

	set("item_desc", ([
		"paizi" : "公平交易\n",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));

	setup();
	replace_program(ROOM);
}

