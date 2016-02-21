// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("花满城", ({ "huaman" }) );
	set("gender", "男性" );
	set("age", 41);
	set("title", BLU "月老" NOR);
	set("long",
		"这位老板正对你露出慈祥的笑容。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/purple_flower":30,
                __DIR__"obj/red_flower":25,
                __DIR__"obj/yellow_flower":33,
                __DIR__"obj/blue_flower":44,
                __DIR__"obj/white_flower":14,
                __DIR__"obj/black_flower":10,
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
	switch( random(5) ) {
		case 0:
message_vision("$N笑着说道：各种新鲜花朵，买些回去给你的心上人吧。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"要买什么花儿？\n",this_object(),ob);
			break;
	}
}
