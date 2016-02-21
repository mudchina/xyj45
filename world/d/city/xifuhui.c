// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "喜福会");
        set ("long", @LONG

这里正在举行一个喜宴，堂内张灯结彩，台上高点红烛，一些歌女舞
娘正随乐而舞，四五个小伙计麻利的上菜送酒。周围坐满了前来祝贺
的客人，热闹非凡。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "down" : __DIR__"ziyanglou",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/boss" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 4,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


