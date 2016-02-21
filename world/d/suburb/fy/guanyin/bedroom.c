// 
// 

inherit ROOM;
void create()
{
        set("short", "精致卧房");
        set("long", @LONG
没有妆台，没有绣被，没有锦帐流苏，也没有任何华贵的阵设，糜奢
的珍玩，眩目的珠宝。这屋子的精致，正如天生丽质，若搽脂粉，反而污
了颜色。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"mirror",
]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
        setup();
        replace_program(ROOM);
}
void reset()
{
	object master;
	if(master = present("master guanyin",this_object()))
		destruct(master);
::reset();
}
