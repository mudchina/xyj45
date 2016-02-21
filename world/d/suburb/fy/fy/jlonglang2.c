
inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
一人多高，只容两人并行的檀香木走廊，廊中的两侧陈列着一些奇花异草。滚滚
热气从走廊的一头冒出，将檀木地板打得又湿又滑，你几乎要扶着栏杆才不会滑倒。
LONG
        );
        set("exits", ([
                "south" : __DIR__"jlonglang1",
		"west" : __DIR__"jlonglang3",
        ]));
        setup();
        replace_program(ROOM);

}
