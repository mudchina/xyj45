inherit ROOM;
void create()
{
        set("short", "玉龙珠宝店");
        set("long", @LONG
珠宝店的正中是块千年古玉雕成的祥龙，玉龙活灵活现，穿梭于祥云之中。龙嘴中
含玉球，玉球有拳头大小，翠绿欲滴。龙眼半睁半闭。四周的墙上挂满了各种金玉制
品和各种护身吉祥玉器。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/jadeowner" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
