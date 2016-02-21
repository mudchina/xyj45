// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("普生", ({ "pusheng" }) );
	set("gender", "男性" );
	set("age", 31);
	set("title", GRN "赛华陀" NOR);
	set("long",
		"这位普生堂老板武功，医道精湛。救死扶伤无数。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/sendrug":12,
                __DIR__"obj/keedrug":22,
                __DIR__"obj/gindrug":12,

	]) );
	set_skill("unarmed",50);
	set_skill("dodge",150);
	set_skill("changquan",150);
	map_skill("unarmed", "changquan");
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
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
	switch( random(20) ) {
		case 0:
message_vision("$N望了$n一眼，低声说道：你面黄肌瘦，肾水亏空，是否．．．过度？\n",this_object(),ob);
			break;
	}
}
