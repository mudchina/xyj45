// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "柳记布庄");
        set ("long", @LONG

长安柳家的布料生意做到现今老板柳云天手上已是三代，生意是一日
好过一日。城中有钱人家要买衣物，准是到这来选。正面有一张紫桐
木的长台，后面橱中挂满了各式各样的衣物，鞋冠之类。往来客人不
断，确是生意兴隆。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/liu" : 1,
                "/d/obj/misc/tables" : 1,
                "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


