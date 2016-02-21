// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "长安府");
        set ("long", @LONG

这是长安城的行政机关，负责城里的大小事件。无论是偷鸡摸狗的小
贼，还是杀人放火的强盗，都会在这里受到应有的处罚。东边墙上贴
的是一些告示(gaoshi)，写着近来审案的结果，北边是大堂。
LONG);
set("item_desc",(["gaoshi":"
       ***********************
       **     官府通告      **
       ***********************\n"
]));

        set("exits", 
        ([ //sizeof() == 4
     "south" : __DIR__"baihu-w2",
                "north" : __DIR__"datang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yayi" : 6,
        ]));


//        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
        if (objectp(present("yayi", environment(me)))) {
                if(!present("zhuang zi", me)) 
return notify_fail("衙役喝道：公堂岂可乱闯，还不退下！\n");
                }
        return ::valid_leave(me, dir);
        }
        return 1;
}

