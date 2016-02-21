// 
// 

inherit NPC;
void create()
{
	set_name("沉香镇的地头蛇", ({ "gangster" }) );
	set("gender", "男性" );
	set("age", 27);
	set("long", "这个人是专门在沉香镇不务正业，坐地分赃的。\n");
	set("combat_exp", 1000);
	set("str", 27);
	set("force", 30);
	set("leave_msg", "溜哒开了");
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"沉香镇的地头蛇喝道：老子就是看你不顺眼，你怎么着？\n",
		(: random_move :)
	}) );
	carry_object("/obj/cloth")->wear();
	add_money("silver", 5);
}
