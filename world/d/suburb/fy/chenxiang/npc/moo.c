// 
// 

inherit NPC;
void create()
{
	set_name("磨菜刀的", ({ "moman" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人是专门帮人磨剪子和锵菜刀的。\n");
	set("combat_exp", 10);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"磨菜刀的高声吆喝道：磨剪子喽～锵菜刀～～～\n",
		(: random_move :)
	}) );
	carry_object("/obj/cloth")->wear();
	add_money("coin", 5);
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
