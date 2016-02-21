// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "铁匠铺");
        set ("long", @LONG

这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，屋子的
角落里堆满了象斧子、铁锤、长剑等各式铁器，叮叮当当的声音敲得
满屋子响。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"qinglong-e3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tiejiang" : 1,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

