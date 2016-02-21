
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

#include <ansi.h>
void create()
{
	set_name("阿飞", ({ "afei", "fei","feia" }) );
	set("gender", "男性" );
        set("title", HIG "情为何物" NOR);
	set("age", 20);
	set("int", 30);
	set("per", 30);
	set("long",
		"天下无敌－－－阿飞\n"
		);
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 30000);
        set("force", 30000);
	set("force_factor", 300);
	set("cor",200);
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("sword", 10);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("literate", 100);
	set_skill("dodge", 200);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
        }) );
	set_skill("sharen-sword", 100);
        map_skill("sword", "sharen-sword");

	setup();
	carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}
int accept_fight(object me)
{
        command("grin");
        command("say 我的剑是用来杀人的，不是用来比划着玩的．");
        return 0;
}
void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "林仙儿")
		{
		message_vision("$N冷笑一声道：我看你活得太长了。\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}
