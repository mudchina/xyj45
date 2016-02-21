inherit ROOM;
void create()
{
        set("short", "一品居");
        set("long", @LONG
各地的名茶这里都有的卖。这里冲茶的水也是从枫叶泉专程汲来的。这里冲茶的壶
更是名贵的紫砂壶。这里冲茶的方法也是最讲究的。每壶茶的第一杯是用来养壶的。所
以这里冲出的茶都有一种纯厚的香气。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind3",
  "up" :   __DIR__"yitea2",
]));
        set("objects", ([
        __DIR__"npc/teawaiter" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
