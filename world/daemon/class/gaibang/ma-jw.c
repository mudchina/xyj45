// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("马俱为", ({"ma juwei", "ma", "juwei"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位武艺精强，却沉默寡言的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("max_kee", 360);
	set("max_gin", 300);
	set("force", 710);
	set("max_force", 710);
	set("jiali", 36);
	
	set("combat_exp", 69000);
	
	set_skill("force", 75); 
	set_skill("huntian-qigong", 72); 
	set_skill("unarmed", 75); 
	set_skill("xianglong-zhang", 75); 
	set_skill("dodge", 68); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 70); 
	set_skill("staff", 75); 
	set_skill("begging", 70); 
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( ob->query("con") < 20 ) return;
	command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
	command("recruit " + ob->query("id"));
}
