// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "袁氏草堂");
        set ("long", @LONG

这里是袁守诚先生算卦测字的地方。提起袁守诚，长安城中无人不晓，
他乃是当朝钦天监台正先生袁天罡的叔父。小屋里整日访客络绎不绝。
但袁先生是个坐不住的人，经常在长安城里闲逛，所以这个小屋里也
常常没有人。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"wailiu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shouchen" : 1,
     __DIR__"npc/xiushi" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



