// Room: /d/xingxiu/xxh1.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
东面石壁上一道裂缝通到一个山洞。
LONG
        );
        set("exits", ([
             "north" : __DIR__"xxh2",
             "southup" : __DIR__"tianroad2",
]));
        set("objects", ([
                "/daemon/class/xingxiu/zhaixing" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

