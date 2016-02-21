// 
// 

inherit NPC;
void create()
{
	set_name("挑山夫", ({ "labor" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人是以往山上挑东西为生的。\n");
	set("combat_exp", 1000);
	set("str", 27);
	set("force", 30);
	set_skill("staff",10);
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	carry_object("/obj/cloth")->wear();
	add_money("coin", 5);
	carry_object(__DIR__"obj/biandan")->wield();
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say 多谢这位" + RANK_D->query_respect(me) + "！");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}
