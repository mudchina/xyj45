// 
// 

inherit ROOM;
void create()
{
        set("short", "右弄堂");
        set("long", @LONG
透过枯梅堂挂着竹帘的偏窗，依稀可以看到堂内的景象。堂内
的白烟从竹帘的缝隙流出，随即被微微山风吹散，整个正堂沉浸在
烟雾飘渺之中。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"frontyard",
  "northeast" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/cat": 1,
	__DIR__"npc/ass" : 2,
                        ]) );
        setup();
        replace_program(ROOM);
}
