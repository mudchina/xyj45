// zhike.c 知客

inherit NPC;

void create()
{
	set_name("知客道长", ({ "zhike daozhang", "zhike" }));
	set("long", 
		"他是武当山的知客道长。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_kee", 300);
	set("max_gin", 200);
	set("force", 300);
	set("max_force", 300);

	set("combat_exp", 5000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 20);
	set_skill("taoism", 20);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 4, "弟子");

	setup();
	carry_object("/d/obj/clone/weapon/changjian")->wield();
}
