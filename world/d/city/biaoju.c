// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "镖局大院");
        set ("long", @LONG

振远镖局的创始人是老英雄萧振远。萧老英雄年事已高，早已不过问
江湖是非了。现在镖局的对外事务都由萧振远的次子萧升主理。大院
左右是厢房，靠墙放了些兵器。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"qinglong-e2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoshen" : 1,
     __DIR__"npc/biaotou" : 2,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

