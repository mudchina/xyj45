// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "青龙大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，西面就快到城中心了，可以看到钟楼
耸立于前。南北皆是规模不小的宅院，北面的院门的牌匾上写着斗大
的“振远镖局”四字，南面的一所宅院是当朝将军秦叔宝的宅第。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : "/d/jjf/gate",
                "north" : __DIR__"biaoju",
                "west" : __DIR__"qinglong-e1",
                "east" : __DIR__"qinglong-e3",
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

