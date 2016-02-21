// 
// 

inherit ROOM;
void create()
{
        set("short", "风云天骄门");
        set("long", @LONG
这是一座古老而神圣的大理石门，大约建于百年前。门上斑斑点点，
风化不堪。传说中是玉皇大帝临凡佳奖天下儿女英雄的地方，凡是被佳
奖的英雄都成为不死之身。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"ecloud5",
]));
        set("objects", ([
        __DIR__"npc/player1" : 1,
        __DIR__"npc/player2" : 1,
        __DIR__"npc/player3" : 1,
        __DIR__"npc/player4" : 1,
        __DIR__"npc/player5" : 1,
        __DIR__"npc/player6" : 1,
        __DIR__"npc/player7" : 1,
        __DIR__"npc/player8" : 1,
        __DIR__"npc/player9" : 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
