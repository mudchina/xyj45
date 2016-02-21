// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "木器铺");
        set ("long", @LONG

这是一家专售木器的小店，店面不大，却很整洁。所卖木器不过是些
木刀，木枪之类，鲁老板也整日闲逛，无所事事。但私下听说他有门
祖传手艺，确谁也没见过。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"xuanwu-n1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/lu" : 1,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


