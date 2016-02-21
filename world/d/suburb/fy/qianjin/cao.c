inherit ROOM;
void create()
{
        set("short", "湖上草");
        set("long", @LONG
湖上草，碧翠浪通津。
修带不为歌舞缓，浓铺堪作醉人茵，无意衬香衾。
晴霁后，颜色一般新。
游子不归生满地，佳人远意正青春，留咏卒难伸。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lastbridge",
  "southeast" : __DIR__"hua",
]));
        set("objects", ([
        __DIR__"npc/cao" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
