inherit ROOM;
void create()
{
        set("short", "西云大路");
        set("long", @LONG
宽宽的黄土路向东西方向伸展，路边的茅屋矮小而破旧，街边的垃圾散发着
令人作呕的腐臭，路上的行人面黄肌瘦，被贫困的生活拖得疲惫不堪。偶而有一
两个面色红润之人，都掩鼻匆匆而过，生怕沾上一点晦气。南首有一扇木门，上
面写道：每夜五十文，北首则是相面大师乙成仙的招牌：生死已卜。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"futhur",
  "south" : __DIR__"cheaph",
  "west"  : __DIR__"wcloud4",
  "east"  : __DIR__"wcloud2",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
