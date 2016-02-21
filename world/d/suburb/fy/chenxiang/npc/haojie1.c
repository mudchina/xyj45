// 
// 

inherit NPC;
void create()
{
	set_name("武林大豪杰", ({ "toughman" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人一看就象是武林中人。\n");
	set("combat_exp", 100000);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		"武林大豪杰高声骂道：老子的刀都砍钝了，鸟也没发现一个！\n",
	}) );
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/miaodao")->wield();
	add_money("gold", 1);
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
