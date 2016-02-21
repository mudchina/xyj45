// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("冷红儿", ({ "lehong" }) );
	set("gender", "女性" );
	set("age", 21);
	set("title", "草药店老板娘");
	set("long",
		"这位老板娘正斜依在柜台边，笑咪咪地望着你。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/renshen":12,
		__DIR__"obj/lurong":6,
		__DIR__"obj/xiong":3,

	]) );
	set_skill("unarmed",50);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/bigcloth")->wear();
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
message_vision("$N满脸含笑，有意无意的用眼角瞟了$n一眼。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N纤腰微摆，露出羊脂般的玉臂，向$n招了招手。\n",this_object(),ob);
			break;
		case 2:
message_vision("$N望了$n一眼，用玉手掩着樱桃小嘴轻笑起来。\n",this_object(),ob);
			break;
	}
}
