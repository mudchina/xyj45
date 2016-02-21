inherit ROOM;
void create()
{
        set("short", "一品居二楼");
        set("long", @LONG
站在这里，打开小窗就可以看到对面银钩赌坊那闪亮，在风中摇曳的银钩。再往远
处看，便是一片梅林。梅林中露出一角小楼，那正是小李飞刀昔日读书学剑的地方。
梅林无恙，但仿佛比几年前开的更胜了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" :   __DIR__"yitea",
]));
        set("objects", ([
	__DIR__"npc/lson" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
