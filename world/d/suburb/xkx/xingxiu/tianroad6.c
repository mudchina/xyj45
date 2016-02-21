// room: /d/xingxiu/tianroad6.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "天山顶峰");
        set("long", @LONG
这里是天山顶峰。从这里向周围望去，帕米尔高原的风光尽收眼底。东面
一条小路可以下山。
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"tianroad5",
        ]));
        set("objects", ([
               __DIR__"npc/snake" : 2, 
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

