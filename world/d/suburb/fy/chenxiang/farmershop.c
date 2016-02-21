// 
// 

inherit ROOM;
void create()
{
        set("short", "农具店");
        set("long", @LONG
墙上挂着各式各样的农具样品，每样都是用煺过火的精铁打造，再配以
上好的木柄，就算是砍在石头上，刃也不会崩，柄也不会断。一张暗红色的
柜台横放在屋子中间，柜台上还放着几块用来试刀刃的木块。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs1",
]));
        set("objects", ([
        __DIR__"npc/farmowner": 1,
	__DIR__"npc/haojie1": 1,
	__DIR__"npc/haojie": 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
