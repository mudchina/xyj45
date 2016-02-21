// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小童", ({ "xiaotong" }) );
	set("gender", "男性" );
	set("age", 14);
	set("long",
		"一个天真无邪的小童\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/white_towel":10,

	]) );
	set_skill("unarmed",5);
	set_skill("dodge",5);
	setup();
	carry_object(__DIR__"obj/yellow_cloth")->wear();
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
