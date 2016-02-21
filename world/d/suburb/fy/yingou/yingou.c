inherit ROOM;
void create()
{
        set("short", "银钩赌坊");
        set("long", @LONG
银钩赌坊布置豪华，充满了温暖和欢乐，酒香中混合着上等脂粉的香气，银钱
敲击，发出一阵阵清脆悦耳的声音。世间几乎没有任何一种音乐能比得上。银钩赌
坊实在是个很奢侈的地方，随时都在为各式各样奢侈的人，准备着各式各样奢侈的
享受。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/suburb/fy/fy/swind3",
  "west" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/xiazi" : 1,
        __DIR__"npc/daniu": 1,

                        ]) );

        setup();
        replace_program(ROOM);
}
