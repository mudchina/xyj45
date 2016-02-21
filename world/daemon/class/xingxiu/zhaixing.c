// zhaixing.c 摘星子

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "星宿派大师兄");
	set("long", 
		"他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
		"他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_kee", 700);
	set("max_gin", 700);
	set("force", 1500);
	set("max_force", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("unarmed", 80);
	set_skill("xingxiu-duzhang", 80);
	set_skill("parry", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "xingxiu-duzhang");
//	map_skill("parry", "tianshan-zhang");
//	map_skill("staff", "tianshan-zhang");

	create_family("星宿派", 2, "弟子");

	setup();
//	carry_object("/d/obj/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
