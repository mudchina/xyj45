
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
                "east" : __DIR__"jlong",
		"north" : __DIR__"jlonglang2",
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
           if( random((int)me->query("kar")) < 2 )
              {
               message_vision("$N脚下一个不稳，四脚朝天地摔在地上。\n\n",me);
               this_player()->unconcious();
               return 0;
              }
	if(  dir == "north" && (string)me->query("gender") != "男性")
	return notify_fail("这是男人浴室，你冲进去作什么？\n");
	return 1;
}

