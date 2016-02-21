// Room: "/d/green/field0.c

inherit ROOM;

void create()
{
	set("short", "小广场");
	set("long", @LONG
这是一个小小的广场，地上铺著切割整齐的大石块。广场周围有几间
屋子，其中以正南边那栋木屋最为特别。往西是一条窄窄的小巷子，往东
则是连接著采石场的空地。中央有一棵大榕树，像一座凉亭般地立在广场
上。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/suburb/es/green/path8",
  "south" : "/d/suburb/es/green/house4",
  "north" : "/d/suburb/es/green/house2",
  "east" : "/d/suburb/es/green/field1",
]));

	setup();
	replace_program(ROOM);
}
