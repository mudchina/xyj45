// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "青龙大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，西面就快到城中心了，可以看到钟楼
耸立于前。北面是一家杂货行，时不是有马车出入送货。南边是一家
兵器铺子，是城内的振远镖局开的，专卖一些兵器。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"bingqipu",
                "north" : __DIR__"zahuohang",
                "west" : __DIR__"center",
                "east" : __DIR__"qinglong-e2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

