// xuanwumen.c 玄武门
// by Xiang

inherit ROOM;

void create()
{
	set("short", "玄武门");
	set("long", @LONG
	在你的面前是一座高大的石坊，上面写着“玄武门”三个镏金大字，由
于年代久远，久经日晒雨淋，已经显得有些黯淡。再往上是一座道观，往下则是
一条石阶路一直通到山下。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie3",
		"northup" : __DIR__"guangchang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhike" : 1]));
	setup();
	replace_program(ROOM);
}

