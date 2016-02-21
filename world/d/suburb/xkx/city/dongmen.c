// Room: /city/dongmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
	这是东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着几张
官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心为妙。一条笔直
的青石板大道向东西两边延伸。东边是郊外，隐约可见一片一望无际的树林，神
秘莫测。西边是城里。北面有一片茂盛的青竹林。
LONG
	);
        set("outdoors", "city");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/suburb/xkx/taishan/yidao",
		"north" : __DIR__"ml1",
		"west" : __DIR__"dongdajie2",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

