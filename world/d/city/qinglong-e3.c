// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "青龙大街");
        set ("long", @LONG

你走在一条宽阔的石板大街上，西面就快到城中心了，可以看到钟楼
耸立于前。北面有家铁匠铺，传出钉钉铛铛的声音。南面是城中的清
虚观，有些道士模样的人出入。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"qingxuguan",
                "north" : __DIR__"tiejiangpu",
                "west" : __DIR__"qinglong-e2",
                "east" : __DIR__"qinglong-e4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/youxia" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

