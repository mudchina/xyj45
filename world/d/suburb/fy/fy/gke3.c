inherit ROOM;
void create()
{
        set("short", "镖局厢房");
        set("long", @LONG
房间里布置很简单，只有一张小床，一个小几，和几张方凳。窗台上放着一个磁杯，
杯里插着几枝无名小花。房间虽不大，但是给人整洁舒适的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ginhall",
]));
        set("objects", ([
        __DIR__"npc/resting_biao" : 2,
                        ]) );
        setup();
        replace_program(ROOM);
}
