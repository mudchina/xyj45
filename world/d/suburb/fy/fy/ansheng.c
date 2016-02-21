inherit ROOM;
void create()
{
        set("short", "安生棺材店");
        set("long", @LONG
店门口的招牌是几个已被雨淋日晒得变了颜色的花圈。店口的地上放着几口打造好，
但还没有上漆的薄皮棺材。 四面的墙上零乱的挂着几串纸钱和纸花。墙角放着一口上
好的红木棺材，但棺盖似乎并没有盖好。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud4",
]));
        set("objects", ([
        __DIR__"npc/cafen" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
