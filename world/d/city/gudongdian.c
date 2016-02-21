// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "古董店");
        set ("long", @LONG

大盖城中有钱人家都爱收藏个古董，所以这店中生意也是不坏。四五
个精明的伙计正陪着客人看货还价。店中摆着各种各样的古货，墙上
的画，架上的瓶，柜里的玉，每样看起来都那么珍贵，让人爱不释手。
买的人虽多，却没人知道林老板是从哪进的货。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "west" : __DIR__"wailiu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/lin" : 1,
                "/d/obj/misc/tables" : 3,
                "/d/obj/misc/chairs" : 6,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



