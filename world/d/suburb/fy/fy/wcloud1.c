inherit ROOM;
void create()
{
        set("short", "西云大路");
        set("long", @LONG
风云广场在东，知府衙门在西，这里是风云城中风骚文人丛聚之地。据说天下
赫赫有名的小李探花就是在这里中的秀才。南边的考场每年都举行一次选拔考试，
前三名送入京都再试。北面则是探花诗台，是风骚文人们留下他们得意之作的地
方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/song": 1,
                        ]) );


        set("outdoors", "fengyun");
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me) && dir == "north")
	if( sizeof(me->query_all_condition()) != 0 )
	return notify_fail("探花诗台不是你的坟场．\n");
	
	return 1;
}
