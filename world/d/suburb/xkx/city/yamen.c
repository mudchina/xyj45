// Room: /city/yamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
	这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分
放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前
巡逻。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}
