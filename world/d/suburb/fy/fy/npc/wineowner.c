// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("驼背老汉", ({ "han" }) );
	set("gender", "男性" );
	set("age", 55);
	set("long",
		"这位老汉好象快不行了．．．\n");
	set("combat_exp", 50);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/nujiu":30,
                __DIR__"obj/xiaocai":35,
	]) );
	set_skill("unarmed",5);
	setup();
	carry_object("/obj/cloth")->wear();
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
message_vision("$N沉重的喘吸着，勉强抬起头看$n一眼。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N直了直腰，勉强向$n招了招手。\n",this_object(),ob);
			break;
	}
}
