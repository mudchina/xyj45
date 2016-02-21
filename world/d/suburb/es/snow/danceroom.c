// Room: "/d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "晚月庄");
        set("long", @LONG
这是一间歌舞院，这里有许多美貌的女孩子正在学习着歌艺和舞蹈。一位仙女
般的女舞者正在教她们跳各种美丽的舞蹈。在这里，你忍不住也想去和她们一起
跳起来。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"crossroad",
]));
        set("objects", ([
                CLASS_D("dancer") + "/master":1 ]) );
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
