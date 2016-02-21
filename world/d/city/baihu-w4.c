// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "白虎大街");
        set ("long", @LONG

这里已是白虎大街的西段，北面小巷里隐约看到一座大的庙宇，那是
长安城的城隍庙，是个热闹的场所。耍把式卖艺的，卖小吃糕点的，
都可以看到。是个三教九流，鱼龙浑杂之地。而南面巷中却很难看到
几个人影，偶有行人也是低头快步而过。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"beiyin1",
                "north" : __DIR__"wailiu1",
                "west" : __DIR__"ximen",
                "east" : __DIR__"baihu-w3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}



