// liangongfang.c 练功房
// by Xiang

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
	这里是练功房，地下凌乱地放着几个蒲团，几位武当弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
		"west" : __DIR__"donglang2",
	]));
	set("objects", ([
		"/d/suburb/xkx/village/obj/zhujian" : 1]));

	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
