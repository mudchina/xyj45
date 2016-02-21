//m_weapon .....tianjianshi.c

inherit ROOM;

void create()
{
	set("short", "沙漠绿洲");
	set("long",
	     "这里是沙漠中不多的一块绿洲，向南不远隐约可以看见一座黑黑的山洞。随风传来一些\n"
	     "叮叮当当的打铁的声音。也不知是谁在打造什么。\n"

	);
	set("exits", ([
		"east" : "/d/suburb/fy/xingxiu/nanjiang2",
		"south" : __DIR__"xuanbing",
	]));
	setup();
	replace_program(ROOM);
}
