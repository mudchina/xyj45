// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "包子铺");
        set ("long", @LONG

贾家兄弟几年前合开了这间包子铺，盖因其用料讲究，又有不传秘方，
生意是一日好过一日，在城中也闯出了名声。店中摆了十几张八仙桌，
几个小伙计来来回回忙活着。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"wailiu1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jia" : 1,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



