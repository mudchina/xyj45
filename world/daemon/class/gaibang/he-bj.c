// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("何不净", ({"he bujing", "he", "bujing"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"这是位衣著邋塌，蓬头垢面的丐帮七袋弟子。\n");
	set("attitude", "heroism");
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);

	set("max_kee", 380);
	set("max_gin", 300);
	set("force", 680);
	set("max_force", 680);
	set("jiali", 34);
	
	set("combat_exp", 70000);
	
	set_skill("force", 70); 
	set_skill("huntian-qigong", 75); 
	set_skill("unarmed", 75); 
	set_skill("xianglong-zhang", 75); 
	set_skill("dodge", 65); 
	set_skill("xiaoyaoyou", 70); 
	set_skill("parry", 73); 
	set_skill("begging", 60); 
	set_skill("stealing", 70); 
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	setup();
}

void attempt_apprentice(object ob)
{
	if( ob->query("combat_exp") < 30000 ) return;
	command("say 你很爱打架吧？ 哈哈哈，好吧，我就收下你了！");
	command("recruit " + ob->query("id"));
}
