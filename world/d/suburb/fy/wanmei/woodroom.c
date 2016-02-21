inherit ROOM;
// 
// 


void create()
{
        set("short", "小柴房");
        set("long", @LONG
一间小而简陋的木屋，但并不漏雨。墙角整齐地堆着一捆捆
干柴。墙上钉着一个木架，架上挂着一些砍柴用的工具。一条长
凳放在屋子中央。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/chair": 1,
	__DIR__"obj/rope" : 1,
	__DIR__"obj/drywoods" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
