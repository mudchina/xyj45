// Npc: /d/shaolin/npc/shaofan-seng.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("烧饭僧", ({
		"shaofan seng",
		"shaofan",
		"seng",
	}));
	set("long",
		"这是位胖胖的中年僧人，大概是因为长年烧饭作菜的缘故，才如此发福的吧。\n"
	);


	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 44);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 400);
	set("max_gin", 200);
	set("force", 100);
	set("max_force", 100);
	set("jiali", 10);
	set("combat_exp", 2000);
	set("score", 100);

	set_skill("force", 12);
	set_skill("dodge", 12);
	set_skill("unarmed", 12);
	set_skill("parry", 12);


	setup();

}



