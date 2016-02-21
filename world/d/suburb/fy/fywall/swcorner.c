inherit ROOM;
void create()
{
	object con,item;
        set("short", "西南角楼");
        set("long", @LONG
角楼上挂着一口铜钟，每当有紧急情况，守城卫兵们就鸣钟为警。调动官兵，共
剿江洋大盗。角楼的中间有一个巨大的烟炉，里面装满了狼粪，以备外族来犯。角楼
里还安装了一门火炮，墙角里还堆着一些火炮丸。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wwall10",
  "east"  : __DIR__"swall10", 
]));
        set("objects", ([
        __DIR__"npc/wall_solider" : 3,
        __DIR__"obj/corner" : 1,
        __DIR__"obj/bomb": 1,
                        ]) );

        set("outdoors", "fengyun");
        setup();
        con = present("corner",this_object());
        item = present("bomb",this_object());
        if( con && item)
        item->move(con);


}
