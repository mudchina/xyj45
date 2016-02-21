// ning.c 宁中则

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("宁中则", ({ "ning zhongze", "ning", "zhongze", "shiniang" }));
	set("long", 
"宁中则女士是掌门人岳不群的师妹兼妻子，虽然已步入\n"
"中年，但风韵依旧。其武功只比岳不群略逊而已。\n");

	set("gender", "女性");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 35);
	set("con", 30);
	set("per", 30);
	
	set("kee", 2200);
	set("max_kee", 2200);
	set("gin", 1600);
	set("max_gin", 1600);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 30);

	set("combat_exp", 1000000);
	set("score", 150000);

	set_skill("force", 180);
	set_skill("dodge", 150);
	set_skill("parry", 120);
	set_skill("sword", 200);
	set_skill("cuff", 100);
	set_skill("blade", 180);
	set_skill("zixia-shengong", 180);
	set_skill("huashan-jianfa", 150);
	set_skill("huashan-shenfa", 140);
	set_skill("hunyuan-zhang", 150);
	set_skill("poyu-quan", 80);
	set_skill("fanliangyi-dao", 150);
	set_skill("literate", 90);
	set_skill("strike", 160);

	map_skill("dodge", "huashan-shenfa");
	map_skill("force", "zixia-shengong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "poyu-quan");
	map_skill("blade", "fanliangyi-dao");

//	prepare_skill("strike", "hunyuan-zhang");
//	prepare_skill("cuff", "poyu-quan");

	create_family("华山派", 13, "弟子");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.wushuang" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"含嫣" : "含嫣就是新东方故事里的那个老太太，很漂亮的说。\n",
		"木客" : "您说的是Wooder吧，他已经工作了！没事可以找他打桥牌。\n",
	]));

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "女性") {
		command("say 阁下开什么玩笑！我怎么能够收男子为徒呢？真是羞人嗒嗒的。");
		return;
	}

	if ((int)ob->query("shen") < 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_dex() < 20) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我华山派武功？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");
