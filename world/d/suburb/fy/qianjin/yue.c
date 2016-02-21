inherit ROOM;
void create()
{
        set("short", "湖上月");
        set("long", @LONG
湖上月，偏照列仙家。
水浸寒光铺枕簟，浪摇晴影走金蛇，偏称泛灵槎。
光景好，轻彩望中斜。
清露冷侵银兔影，西风吹落桂花枝，开宴思无涯。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"grassroom",
  "northwest" : __DIR__"liu",
]));
        set("objects", ([
        __DIR__"npc/yue" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
