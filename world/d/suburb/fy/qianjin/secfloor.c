inherit ROOM;
void create()
{
        set("short", "云雨舟二层");
        set("long", @LONG
应入眼帘，首先是一幅占据了一面墙的春宫图，无疑为名家所著。画法细腻，
毫发尽现。金盏玉杯，红烛粉黛构成了一种奇特的胁调。厅正中放着几张玉石圆
桌，桌上杯盏参差。再往上则是千金楼最昂贵的不眠阁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"stairs2",
  "northup" : __DIR__"jinge",
]));
        set("objects", ([
        __DIR__"npc/dapiaoke" : 1,
	__DIR__"npc/dachick": 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
