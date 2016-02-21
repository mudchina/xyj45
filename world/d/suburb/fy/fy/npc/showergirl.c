// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小丫环", ({ "yahuan" }) );
	set("gender", "女性" );
	set("age", 14);
	set("title", "如花似玉");
	set("long",
		"一个天真无邪的小丫环\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/white_towel":11,

	]) );
	set_skill("unarmed",5);
	set_skill("tenderzhi",5);
	set_skill("dodge",5);
	set_skill("stormdance",5);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/green_cloth")->wear();
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
	switch( random(3) ) {
		case 0:
message_vision("$N在百忙中抬起头望了$n一眼。\n",this_object(),ob);
			break;
	}
}
