// worker.c

inherit NPC;

void create()
{
        set_name("忏悔徒", ({ "chantu", "tu" }) );
        set("gender", "女性" );
        set("age", 19);
	set("title","泪流满面");
        set("long", "一个泪流满面的忏悔徒\n");
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
        carry_object("/obj/cloth")->wear();
}

