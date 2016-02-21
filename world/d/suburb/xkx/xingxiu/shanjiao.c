// tianshan: /d/xingxiu/shanjiao.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "天山脚下");
        set("long", @LONG
这里是天山脚下，西面是高耸入云的天山。天晴的时候可以看到山顶
上的冰川。一道天山将西域分为两半。北疆是西域各族的聚居区，南疆是
无边的塔克拉马干大沙漠。
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad1",
            "northwest" : __DIR__"beijiang",
            "southwest" : __DIR__"nanjiang",
            "southeast" : __DIR__"silk4",
]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai" );
        set("objects", ([
            __DIR__"npc/trader" : 1]));

        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    int current_water;
    if (dir == "southwest") {

        if (!userp(me)) return 0;
        current_water = me->query("water");
        if (current_water==0) {
        }

        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }

        if (current_water>20) {
            me->set("water",current_water-20);
        }
        return ::valid_leave(me, dir);
    }
        return ::valid_leave(me, dir);

}
