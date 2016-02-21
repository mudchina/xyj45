// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "总管府第");
        set ("long", @LONG

这里是当朝总管殷开山的府第。大门两侧有两头高大的石狮子。院子
里种满了花草。东边是一棵槐树，郁郁葱葱，遮盖了大半个院子。一
条长廊走道通往后院。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "north" : __DIR__"baihu-w2",
     "south" : __DIR__"zhongguan2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guanjia" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 3,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


