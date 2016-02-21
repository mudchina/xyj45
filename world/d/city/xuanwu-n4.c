// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "玄武大街");
        set ("long", @LONG

这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。远
远的能看到皇宫的朝阳门。东边是长安城的天监台，祭天求雨的仪式
都会在那里举行。西边是座御林军营，保卫着皇宫的安全。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"xuanwu-n3",
                "north" : "/d/huanggong/chaoyangmen",
                "west" : __DIR__"junying",
                "east" : __DIR__"tianjiantai",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//      __DIR__"npc/japan1": 2,
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

