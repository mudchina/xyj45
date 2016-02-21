// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黎生", ({"li sheng", "li", "sheng"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 38);
	set("long", 
		"这是位生性刚直，嫉恶如仇的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);

	set("max_kee", 390);
	set("max_gin", 300);
	set("force", 800);
	set("max_force", 800);
	set("jiali", 40);
	
	set("combat_exp", 79000);
	
	set_skill("force", 81); 
	set_skill("huntian-qigong", 82); 
	set_skill("unarmed", 85); 
	set_skill("xianglong-zhang", 75); 
	set_skill("dodge", 80); 
	set_skill("xiaoyaoyou", 82); 
	set_skill("parry", 82); 
	set_skill("staff", 80); 
	set_skill("begging", 70); 
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( ob->query("sen") < 0 ) return;
	command("say 好，有你这样一等一的人才做我徒弟，我欢喜还来不及呢！");
	command("recruit " + ob->query("id"));
}
