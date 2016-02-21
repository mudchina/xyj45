// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "杂货行");
        set ("long", @LONG

杂货行中并不是很大．里里外外堆的都是货物，看起来非常的拥挤。
货行以为人送货为生财之路，所以信誉相当的好。里面有几个小伙计
正忙着装卸货物，旁边一驾小车等着装货。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/huoji" : 3,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

