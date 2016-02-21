// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
        set("short", "大槐树上");
        set("long", @LONG
你现在正攀附在一株大槐树的树干上，从这里可以很清楚地望见树
下的一切动静，而不被人发觉，似乎是个干偷鸡摸狗勾当的好地方。
LONG
        );
        set("objects", ([
                __DIR__"npc/spy":1 ,
		__DIR__"npc/maque" : 2,
	]) );

        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tanghuai",
]));

        setup();
        replace_program(ROOM);
}
