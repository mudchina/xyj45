// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{

	set_name("家奴", ({ "jianu", "nu" }) );
	set("long", "这是一千金楼的家奴，专门担任打手之责。\n");
	set("attitude", "friendly");

	set("str", 40);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 1000);
	set("chat_chance", 1);
	set("chat_msg_combat", ({
		"家奴喝道：敢在这撒野！活得不耐烦了！\n",
		(: command("crazy") :),

	}) );
	set_skill("unarmed", 10+random(50));
	set_skill("move", 7+ random(70));

	setup();

	carry_object(__DIR__"obj/jncloth")->wear();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIW + name() + "狠狠往地下啐了一口道：下次没这么便宜！\n\n"
		+ name() + "恨恨地跺了跺脚，一溜烟跑了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
