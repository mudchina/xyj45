// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short","破庙密室");
	set("long", @LONG
这是丐帮重要密道之一。由此上往，可直达破庙。四周光线昏暗，
似乎有几个黑暗的洞口在你身边。脚下地上扔满了垃圾，踩上去悉悉
索索地响。
LONG
	);

	set("exits", ([
		"up" : "/d/suburb/xkx/city/pomiao",
		"southwest":__DIR__"zlandao2",
	]));

	setup();
	replace_program(ROOM);
}



