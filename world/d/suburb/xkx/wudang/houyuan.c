// houyuan.c 后院
// by Xiang

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
	这里是后院，南面是三清殿，北面是一个圆形的门洞，有一条小路通往
后山。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"sanqingdian",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/yu" : 1]));
	setup();
	replace_program(ROOM);
}

