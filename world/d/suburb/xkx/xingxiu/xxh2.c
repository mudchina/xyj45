// Room: /d/xingxiu/xxh2.c
// Jay 3/18/96

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里左右两厢通向星宿海的深处，南边是星宿派总舵——日月洞。
洞口立着一个牌子(paizi)。
LONG
        );
        set("exits", ([
             "north" : __DIR__"riyuedong",
             "south" : __DIR__"xxh1",
             "northeast" : __DIR__"xxh3",
             "northwest" : __DIR__"xxh4",
        ]));

        set("item_desc", ([
                "paizi" : "星宿海福地，日月洞洞天。\n",
        ]));

        //set("objects", ([
        //        "/daemon/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
  //      replace_program(ROOM);
        "/d/obj/clone/board/xingxiu_b"->foo();

}

/*
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "星宿派") && dir != "north" &&
                (present("chuchen zi", environment(me)))) {
                say("出尘子对"+me->name()+"喝道：你不是星宿派弟子，不想吃大爷我的钢杖就快滚开。\n");
                return notify_fail("出尘子喝道：你不是星宿派弟子，不想吃大爷我的钢杖就快滚开。\n");
        }
        return ::valid_leave(me, dir);
}
*/

