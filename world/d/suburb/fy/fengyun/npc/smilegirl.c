
inherit NPC;

void create()
{
	set_name("楚楚", ({ "chuchu" }) );
	set("gender", "女性" );
	set("age", 18);
	set("long",
		"一个天真无邪，未懂世事的小丫环\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
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
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
message_vision("$N看了$n一眼，然后捂住小嘴儿开始＂吃吃＂的笑。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N盯了$n身上一眼，然后害羞地转过身，开始＂吃吃＂的笑。\n",this_object(),ob);
			break;
		case 2:
			command("snicker");
	}
}
