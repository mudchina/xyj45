// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("读千里", ({ "duqianli" }) );
	set("gender", "男性" );
	set("age", 81);
	set("title", CYN "才高八斗" NOR);
	set("long",
		"这位老板不但才高八斗，而且还是当今皇太子的老师。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/book" : 10,
                __DIR__"obj/book3" : 20,
                __DIR__"obj/book4" : 20,
                __DIR__"obj/book5" :33,
                __DIR__"obj/book6": 22,
                __DIR__"obj/book7":22,
                __DIR__"obj/book8":11,


	]) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
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
	switch( random(10) ) {
		case 0:
message_vision("$N摇头晃脑地低吟道：良时不再至，离别在须臾。屏营衢路侧．．。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N望了$n一眼，低哼道：结发为夫妻，恩爱两不疑。欢娱在今夕．．。\n",this_object(),ob);
			break;
	}
}
