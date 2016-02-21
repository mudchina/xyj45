// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "城隍庙");
        set ("long", @LONG

城隍庙里香火极盛。大多是来保佑家里平安，生意兴隆之类。正中前
方一座白白胖胖，满脸福相的城隍，左边有一位手持帐簿和毛笔的判
官。一位庙祝走前走后，和大家打着招呼。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"wailiu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/keeper" : 1,
        ]));
   set("no_fight", 1);
   set("no_magic", 1);

//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



