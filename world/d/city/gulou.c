// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "鼓楼");
        set ("long", @LONG

鼓楼是当朝皇上为报时而设，是一座长方形的青砖建筑，看起来相当
的古朴稳重。顶上成拱形，雕有许多鸟兽鱼虫。每到傍晚，沉闷的鼓
声就会随着蔼蔼暮气，在大街小巷中回荡。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"wailiu1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



