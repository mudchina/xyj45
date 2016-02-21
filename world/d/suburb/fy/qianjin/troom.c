inherit ROOM;
void create()
{
        set("short", "私刑房");
        set("long", @LONG
这里是千金楼逼良为娼的地方。每个不肯就范的姑娘都会被关在这里，不给吃喝。
如还不从，则严刑拷打。墙上和地上都有暗红色的血迹。屋角一张肮脏的小床，床上
发灰的床单，似乎还有老鼠咬过的痕迹。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sr2",
]));
       set("objects", ([
        __DIR__"npc/funu" : 2,
	__DIR__"obj/broken_cloth" : 2,
                        ]) );


        setup();
        replace_program(ROOM);
}
