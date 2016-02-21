
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "浸龙浴池");
        set("long", @LONG
一入门，热气扑面，白白的水气立刻包围了你。你依稀看到一个巨大的檀木水池,
水呈碧绿，散发着一种奇特的药香，水面上还漂着一片片红红的花瓣儿，你真想一下
子跳（ｊｕｍｐ）进去，闭上眼睛好好的放松一下。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang3",
        ]));
        set("objects", ([
                __DIR__"npc/troublemaker": 2,
        ]) );
        setup();
        create_door("east", "檀木门", "west", DOOR_CLOSED);

}

void init()
{
	add_action("do_jump", "jump");

}

int do_jump()
{
	object me;
	int wait;
	me = this_player();
	wait = random( 40 - (int)(me->query("con"))) * 2;
	if ( wait <= 20) wait = 21;
	message_vision("$N噗嗵一声跳进浴池．\n",me);
	tell_object(me,"你感到全身无比的舒泰．．\n");
	remove_call_out("curehimup");
	call_out("curehimup", wait, me);
return 1;
}

void curehimup(object me)
{
        int gin,kee,sen;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
	{
	message_vision("$N的精气神全恢复了！！\n", me);
	me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
	me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
	}
return;
}

