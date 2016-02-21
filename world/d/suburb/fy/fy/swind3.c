inherit ROOM;
void create()
{
        set("short", "南风大街");
        set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，街道两侧的
瓦房高大而宏伟，分明是巨富宅院。双人合抱的杨树十步一株，整齐的排在两边。
一个闪亮的银钩挂在大街西面一座巨宅的飞檐下，象征着风云城中最豪赌的银钩
赌坊。银钩赌坊的对面则是一品居茶座。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind4",
  "north" : __DIR__"swind2",
  "east" : __DIR__"yitea",
  "west" : "/d/suburb/fy/yingou/yingou",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
