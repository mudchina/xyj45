// /d/xingxiu/mogaoku.c
// Jay 3/17/96

inherit ROOM;

// can put some book about budism here.

void create()
{
        set("short", "莫高窟");
        set("long", @LONG
这里墙壁上绘制着与佛教相关的画面，有仙女飞天，还有反弹琵琶。洞中
还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。
LONG
        );
        set("exits", ([ 
             "north" : __DIR__"yueerquan",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

