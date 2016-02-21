// room: /d/xingxiu/tianroad5.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "天山山路");
        set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片针叶林。
西边望去，顶峰遥遥可见。南边有个黑黢黢的山洞(cave)。
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad6",
            "eastdown" : __DIR__"tianroad4",
            "enter" : __DIR__"cave",
        ]));
        set("objects", ([
               __DIR__"npc/caiyaoren" : 1, 
        ]));

       set("item_desc", ([
              "cave" : "黑黢黢的山洞里飘出一阵阴风，吓得你直打哆嗦。\n"
       ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

