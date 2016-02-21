// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "喜福会");
        set ("long", @LONG

喜福会是长安城里最有名的一个饭馆了。这里不但常常有京城里的达
官贵人的排场宴请，还每天接待着从各地慕名而来的游人。你刚一踏
进门，店小二就殷勤地迎了上来。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"baihu-w3",
     "up" : __DIR__"xifuhui",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoer1" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


