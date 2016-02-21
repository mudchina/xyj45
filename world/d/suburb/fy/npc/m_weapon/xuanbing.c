//m_weapon .....tianjianshi.c
//xuanbing.c

inherit ROOM;

void create()
{
	set("short", "玄兵古洞");
	set("long",
	     "这里是玄兵古洞洞口，里面传来阵阵的捶打声。似乎在锻造着什么。隐隐\n"
	     "的透着一股萧杀的气息。\n"

	);
	set("exits", ([
		"east" : "/d/suburb/fy/xingxiu/nanjiang2",
		"enter" : __DIR__"xuanbing1",
	]));
	setup();
	replace_program(ROOM);
}
