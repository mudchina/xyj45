// gbandao.c 练功房
// by aji
#include <room.h>

inherit ROOM;

void kick();

void create()
{
        set("short", "暗道");
        set("long", @LONG
	一条狭窄的地下秘密通道，笔直的朝东面延伸。通道的尽头有明亮的
光线透进来。
LONG
        );
        set("exits", ([
		"east" : __DIR__"gbxiaowu",
                "out" : __DIR__"pomiao",
        ]));
	set("objects",([
		CLASS_D("gaibang") + "/jian" : 1
	]));

	create_door("out", "小门", "enter", DOOR_CLOSED);

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "丐帮") && dir == "east" &&
                objectp(present("jian zhanglao", environment(me))))
                return notify_fail("简长老一把揪住你的衣领说：“慢着”\n");
        return ::valid_leave(me, dir);
}

