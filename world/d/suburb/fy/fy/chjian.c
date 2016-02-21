inherit ROOM;
void create()
{
        set("short", "忏悔间");
        set("long", @LONG
一间只容一个人的小房间。房间的一面墙上有孔，这里的声音可以很清晰的传到隔
壁。房间里只有张小木凳和钉在墙上供人放东西的木板。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"church",
]));
        set("objects", ([
        __DIR__"npc/chantou" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
