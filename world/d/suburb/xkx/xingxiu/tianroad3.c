// room: /d/xingxiu/tianroad3.c
// Jay 3/18/96

inherit ROOM;

void init();
int do_jump(string);

void create()
{
        set("short", "天山山路");
        set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片草原。
西面一条深涧(valley)挡住了上山的路。
LONG
        );
        set("exits", ([
            "northup" : __DIR__"xxroad4",
            "eastdown" : __DIR__"tianroad1",
]));
        set("item_desc", ([
                "valley" : "深涧有三丈多宽，不知道能不能跳(jump)过去。\n"
        ]) );

        set("objects", ([
                "/daemon/class/xingxiu/azi" : 1
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="valley" ) {
/*                if (present("horse", me))  { */
                if (me->query_temp("marks/骑") ) {
                        message("vision", me->name() + 
                          "猛地一提缰绳，胯下的伊犁马一声长嘶越过了深涧。\n",
                           environment(me), ({me}) );
                        write("你猛地一提缰绳，胯下的伊犁马一声长嘶越过了深涧。\n");
                        me->move("/d/suburb/xkx/xingxiu/tianroad4");
                        message("vision", "只听得唏溜溜一声马嘶，" + 
 me->name() +  "从深涧的那端纵马跳了过来，好似当年马跳\n檀溪的玄德公。\n",
                        environment(me), ({me}) );
                        write("只听得唏溜溜一声马嘶，你从深涧的那端纵马跳了过来，"
                              "真是酷呆了。\n你乐得从马背上滚了下来。\n");
                        me->set_temp("marks/骑", 0);
                        return 1;
                }
                else {
            write("你试了试，发现深涧的那边比这边高，非是人力可以跳上去的。\n");
                        return 1;
                }
        }
}
