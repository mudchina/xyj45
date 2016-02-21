inherit ROOM;
void create()
{
        set("short", "黄衣室");
        set("long", @LONG
黄衣警卫专门负责金钱帮总舵的安全。凡是来人，都要经过他们的检察。这里是他
们轮班休息的所在。屋中有几张小床，几张小几。每张床头都有小钩，警卫们都把兵
器挂在钩上，一伸手，他们就可以最快的速度拔出自己的兵刃。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jting",
  "south" : __DIR__"jbang",
]));
        set("objects", ([
        __DIR__"npc/huangyi" : 3,
                        ]) );

        setup();
        replace_program(ROOM);
}
