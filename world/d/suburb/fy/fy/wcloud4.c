inherit ROOM;
void create()
{
        set("short", "西云大路");
        set("long", @LONG
宽宽的黄土路向东西方向伸展，路边的茅屋矮小而破旧，街边的垃圾散发着
令人作呕的腐臭，路上的行人面黄肌瘦，被贫困的生活拖得疲惫不堪。偶而有一
两个面色红润之人，都掩鼻匆匆而过，生怕沾上一点晦气。大路南侧的安生棺材
店中迎门放着几口薄皮木棺，大路北面的阿发木器店中黑漆漆一片，从这里根本
看不到里面有什么。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"afa",
  "south" : __DIR__"ansheng",
  "west"  : __DIR__"wcloud5",
  "east"  : __DIR__"wcloud3",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
