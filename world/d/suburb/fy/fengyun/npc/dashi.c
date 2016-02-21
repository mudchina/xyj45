// waiter.c

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("乙成仙", ({ "xian" }) );
	set("gender", "男性" );
	set("age", 45);
	set("title",HIY  "生死已卜" NOR);
	set("long",
		"这位＂生死已卜＂的乙成仙正满眼诡密的忘着你\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",250);
	set("force",10000);
	set("max_force",10000);
	set("force_factor",50);
	set_skill("dodge",50);
	setup();
	carry_object(__DIR__"obj/daopao")->wear();
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
message_vision("$N向$n说道：你印堂发黑，刹气透天庭，三天！三天之内一定横尸街头。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N对$n阴笑一声：你还是去订口棺材吧！\n",this_object(),ob);
			break;
		case 2:
message_vision("$N望了$n一眼，一家大小老少都玩了．．．．\n",this_object(),ob);
			break;
	}
}
