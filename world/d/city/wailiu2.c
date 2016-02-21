// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "歪柳巷");
        set ("long", @LONG

巷子两边是成行的柳树，而柳树皆成扭曲状，故名歪柳巷。巷中有青
石铺成的大路供人行走，两旁是青砖瓦房，来往人物恭而有礼，与城
内的繁华热闹相比却多出几分闲情安逸。北面就是城隍庙，前来赶庙
会上香的人很多。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"wailiu1",
                "north" : __DIR__"chenghuang",
                "west" : __DIR__"caotang",
     "northeast": __DIR__"wailiu3",
                "east" : __DIR__"gudongdian",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yiren1" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



