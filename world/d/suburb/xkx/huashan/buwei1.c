// square.c

inherit ROOM;

void create()
{
        set("short", "客厅");
	set("long", @LONG
这是华山掌门岳不群的居所「有所不为轩」，此处是前厅，厅上挂着
「正气堂」三字匾额。厅中很宽敞，却没什么摆设，靠墙放着两把交椅，
这里是岳不群议事、授徒的地方，后面是寝室。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"square",
  "south" : __DIR__"buwei2",
]));
        set("objects", ([ __DIR__"npc/dayou": 1,
                 ]) );

        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "south" && objectp(present("lu dayou", environment(me))))
                return notify_fail(
"陆大有喝道：后面是家师寝室，这位" + RANK_D->query_respect(me) + "请止步。\n");
        return ::valid_leave(me, dir);
}
 
