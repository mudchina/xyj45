// 
// 

inherit NPC;
void create()
{
	set_name("农家女", ({ "nongnu" }) );
	set("gender", "女性" );
	set("age", 15);
	set("combat_exp", 50);
	set("attitude", "friendly");
	set("per",20);
	set("arrive_msg", "蹦蹦跳跳地跑了过来");
	set("leave_msg", "跑开了");
        set("chat_chance", 15);
        set("chat_msg", ({
                "农家女笑道：请你一起踢，好不好吗？\n",
                "农家女拿起鸡毛毽子踢了几下。\n",
		                (: random_move :)

        }) );

	setup();
	carry_object(__DIR__"obj/jianzi");
	carry_object("/obj/cloth")->wear();
}
