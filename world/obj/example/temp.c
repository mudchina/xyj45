
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("铁少", ({ "tieshao", "master","master tieshao" }) );
	set("gender", "男性" );
        set("title", "多情刀客");
	set("age", 25);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("风云", 0, "庄主");
	set("long",
		"铁少从十五岁开始就和爱妻雪蕊儿行侠江湖，俩人刀剑合壁，\n"
		"天下无敌。正当俩人名声顶盛之时，又忽然退出江湖，隐居于此。\n"
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
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("meihua-shou", 100);
	set_skill("shortsong-blade", 130);
	set_skill("qidaoforce", 150);
	set_skill("fall-steps", 100);

	map_skill("unarmed", "meihua-shou");
        map_skill("blade", "shortsong-blade");
        map_skill("force", "qidaoforce");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");

	setup();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "男性" )
          {      command("say 我只收男弟子，你还是去拜我的内人吧！");
          }
        else {

                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "legend");
        add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
	object xiaocui;
	if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
	{	
        command("smile");
        command("say 还是让小翠来吧。");
        return 0;
	}
	else
		command("sigh");
		command("铁少慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
		command("wield wangblade");
		command("say 请！");
		call_out("do_unwie", 3);
		return 1;
}
int do_unwie()
{
        if( !this_object()->is_fighting())
        {
                command("unwield wangblade");
                message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了雪蕊儿一眼，又坐在竹凳上。\n", this_object());
		command("smile");
                return 1;
        }
        else
                call_out("do_unwie", 3);
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
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = victim->name();
		if( name == "雪蕊儿")
		{
		message_vision("$N皱皱眉头。\n", this_object());
		message_vision("$N从乌皮刀鞘中抽出一把杀气逼人的垓下刀握在手中。\n", this_object());
		weapon = present("wangblade", this_object());
		weapon->wield();
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		call_out("do_unwie", 3);
		return 0;
		}
		if( name == "铁少")
		{
		message_vision("$N皱皱眉头。\n", this_object());
                message_vision("$N从乌皮刀鞘中抽出一把杀气逼人的垓下刀握在手中。\n", this_object());
                weapon = present("wangblade", this_object());
                weapon->wield();
                call_out("do_unwie", 3);
		return 0;
		}
		return 0;
	}
	return 0;		
}
