// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "玄武大街");
        set ("long", @LONG

这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。远
远的能看到皇宫的朝阳门。东边传出朗朗读书声，那里是当朝的学府
国子监。西边是一座富丽堂皇的大院子，那里是招待国宾和外国使节
的宾馆。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"xuanwu-n2",
                "north" : __DIR__"xuanwu-n4",
                "west" : "/d/wiz/entrance",
                "east" : __DIR__"guozijian",
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

