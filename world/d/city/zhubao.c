// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "珠宝行");
        set ("long", @LONG

珠宝行中珠光宝气四射，眩的人有些睁不开眼睛。精致的长柜中陈设
着各类首饰珠宝玉器，几个老行家正陪着客人挑选所需珠宝。一个雕
花木架上摆着颗三尺多高的玉树，珍贵之外又透着淡雅秀丽，曲折含
蓄之气。东边出去是朱雀大街。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"zhuque-s2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jin" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

