// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "朱雀大街");
        set ("long", @LONG

朱雀大街上商家众多，大大小小的店铺比邻而立，看起来是相当的豪
华富足。宽阔的石板路直通南北，向北通到皇宫的朝阳门，向南可遥
望到青青的终南山。西边是家珠宝店，看起来珠光宝气，东边是家老
字号的药铺。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"zhuque-s3",
                "north" : __DIR__"zhuque-s1",
                "west" : __DIR__"zhubao",
                "east" : __DIR__"yaopu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/nanhai/npc/bonze" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

