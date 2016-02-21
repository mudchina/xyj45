// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "玄武大街");
        set ("long", @LONG

这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。远
远的能看到皇宫的朝阳门。南边是城中心，游人相当的多。西边是城
中有名的柳记布庄，专门经销各类服饰。东边是家木器铺。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"center",
                "north" : __DIR__"xuanwu-n2",
                "west" : __DIR__"buzhuang",
                "east" : __DIR__"muqi",
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

