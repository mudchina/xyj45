// tianlang.c 天狼子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("nickname", "星宿派三师兄");
	set("long", 
		"他就是丁春秋的三弟子天狼子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_kee", 400);
	set("max_gin", 400);
	set("force", 1000);
	set("max_force", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("unarmed", 50);
	set_skill("xingxiu-duzhang", 30);
	set_skill("parry", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");

	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/d/obj/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
