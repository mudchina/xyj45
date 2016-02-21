inherit ROOM;
void create()
{
        set("short", "南风大街");
        set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，街道两侧的
瓦房高大而宏伟，分明是巨富宅院。双人合抱的杨树十步一株，整齐的排在两边。
大街西面一对千斤巨鼎，悬挂在朱门两旁。这里就是金钱帮的总舵。
大街东面巨宅上有一高高的十字架，一些金发碧眼，身披黑袍的人不时的出出入入。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind3",
  "north" : __DIR__"swind1",
  "east" : __DIR__"church",
  "west" : __DIR__"jinqian",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
