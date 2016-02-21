// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "小酒馆");
        set ("long", @LONG

小酒馆不大，屋中零乱的摆了几张方桌，几条长凳。小柜台上摆了些
酒坛，所卖也不过是些花生米，老白干之类。累了一天的苦力人总爱
凑到一起喝几杯，吹吹牛，消磨时光。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "west" : __DIR__"beiyin2",
                "south" : __DIR__"beiyin4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaowang" : 1,
     __DIR__"npc/kuli" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


