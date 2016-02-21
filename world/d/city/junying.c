// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "御林军营");
        set ("long", @LONG

京城驻扎着数万禁卫军，保卫皇上的安全，大多驻扎在皇宫周围以确
保皇宫的安全。这里驻扎的是秦琼等人从禁卫军中亲手挑出来的有才
之士。平日里几员将军常来传授武艺。
LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yulinjun" : 3,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

