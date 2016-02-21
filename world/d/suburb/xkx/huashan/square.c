// square.c

inherit ROOM;

void create()
{
        set("short", "练武场");
	set("long", @LONG
这里是华山派的练武场，通常有许多华山派弟子在此习武练剑，所以
不欢迎外人。而今，华山派不知为何举派离山而去，只留几个弟子看家，
他们似乎无心管那么多，就有些游客在此休息。南边的房屋门上挂着一块
匾，上书「有所不为轩」，西北方似乎有条小道通往山上。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yunu",
  "south" : __DIR__"buwei1",
]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
