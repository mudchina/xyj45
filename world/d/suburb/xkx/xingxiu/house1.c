// /d/xingxiu/house1.c
// Jay 3/26/96

inherit ROOM;

void create()
{
        set("short", "巴依家客厅");
        set("long", @LONG
这是巴依家的客厅。地上铺着波斯地毯，木架上摆这中原的瓷器。看得出
这家的主人一定很有钱。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"house",
]));
        set("objects", ([
                __DIR__"npc/afanti": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}


