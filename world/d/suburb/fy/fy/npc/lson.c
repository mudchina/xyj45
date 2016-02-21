
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("龙小云", ({ "xiaoyun" }) );
	set("gender", "男性" );
	set("title", HIR "红孩儿" NOR);
	set("age", 14);
	set("long",
		"一个天真无邪，未懂世事的小还子．．至少表面如此．．．\n");
	set("combat_exp", 5);
	set("attitude", "aggrensive");
	set("per",30);
	set_skill("unarmed",5);
	set_skill("dodge",5);
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
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
message_vision("$N低声道：找到小李飞刀，上官金虹一定会答应收我为徒的．\n",this_object(),ob);
			break;
		case 1:
			command("grin");
			break;
	}
}
