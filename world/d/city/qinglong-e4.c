// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "青龙大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，东边就快要出了城门，远远看到一些
兵卒来回巡逻。西边直通到城中心。北边是城内一个大兵营，里面守
备森严，一般人是不许入内的。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : "/d/eastway/wangnan1",
                "north" : "/d/jjf/yingfang",
                "west" : __DIR__"qinglong-e3",
                "east" : __DIR__"dongmen",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

