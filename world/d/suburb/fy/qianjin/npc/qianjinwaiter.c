// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("徐娘", ({ "xuniang" }) );
	set("gender", "女性" );
	set("age", 54);
	set("title", HIG "徐娘半老，风韵犹存" NOR);
	set("long",
		"这位半老徐娘正用色迷迷的眼神盯着你。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",2);
	set("vendor_goods", ([
                __DIR__"obj/glxj":5,
                __DIR__"obj/cpdx":5,
                __DIR__"obj/pxhy":5,
                __DIR__"obj/kzmt":5,
                __DIR__"obj/hhdq":5,

	]) );
	set_skill("unarmed",50);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/wch_skirt")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
message_vision("$N瞟了$n一眼：渴了饿了吧，来，来，来。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N微摆比水桶稍细一点的腰，露出鸡爪般的手，向$n招了招：来，饿了吧。\n",this_object(),ob);
			break;
		case 2:
message_vision("$N望了$n一眼，用手掩着嘴笑了起来，露出已掉了大半的黄牙。\n",this_object(),ob);
			break;
	}
}
