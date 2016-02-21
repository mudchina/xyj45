// yu.c 俞莲舟

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("俞莲舟", ({ "yu lianzhou", "yu" }));
	set("nickname", "武当二侠");
	set("long", 
		"他就是张三丰的二弟子俞莲舟。\n"
		"他今年五十岁，身材魁梧，气度凝重。\n"
		"虽在武当七侠中排名第二，功夫却是最精。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 1500);
	set("max_gin", 800);
	set("force", 2000);
	set("max_force", 2000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 80000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 80);
	set_skill("unarmed", 80);
	set_skill("taiji-quan", 60);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 80);
//	set_skill("taoism", 80);
//	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");

	setup();
	carry_object("/d/obj/clone/weapon/changjian")->wield();
	carry_object("/d/suburb/xkx/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("sen") < 100) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say " + RANK_D->query_respect(ob) + "若能做出" +
			"几件侠义之事，我一定收你。");
		return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
}
