// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("上了年纪的老太婆", ({ "taipo", "po" }) );
        set("long",
                "风云城中最老的老太婆，风云老小都很尊重她\n");

	set("gender","女性");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("age", 99);
        set("combat_exp", 0);
        setup();
        carry_object("obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_work", "work");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(me->is_busy()) return notify_fail("你的动作还没有完成，不能工作。\n");
message_vision("$N辛苦的工作终于结束了，可人也累的要死\n",me);
me->add("gin",-30);
me->add("sen",-30);
ob = new("/obj/money/silver");
ob->move(me);
message_vision("上了年纪的老太婆对$N说：这是你的工钱。\n", me);
me->start_busy(1);
return 1;
}
