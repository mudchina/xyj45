// worker.c

inherit NPC;

void create()
{
        set_name("裸体女人", ({ "naked girl", "girl" }) );
        set("gender", "女性" );
        set("age", 19);
        set("long", "正在以枫叶泉水疗伤的女人\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);
	set("max_kee",400);
	set("eff_kee",400);
	set("kee",400);

	setup();
}

