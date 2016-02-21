// /d/xingxiu/silk2.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是一条中原和西域之间的商道。南面连绵的祁连山脉在阳光的照射下
好像是一条玉带。东边是中原，西面则通往西域。
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "east" : __DIR__"silk1",
		"northwest" : __DIR__"silk3",
        ]));

        setup();
        replace_program(ROOM);
}

