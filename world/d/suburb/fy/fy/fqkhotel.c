inherit ROOM;
void create()
{
        set("short", "凤求凰客栈");
        set("long", @LONG
前厅挂着一幅龙凤双飞的巨画。当门挂着对鸳鸯球。球上系着几个小小的黄铜风铃。
微风掠过，风铃发出清脆悦耳的叮咚声。大门两侧挂着斗大的大红灯笼，上各书凤凰两
字。朱门上横批一个“求”字。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
