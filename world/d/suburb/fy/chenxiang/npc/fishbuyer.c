// 
// 

inherit NPC;
void create()
{
	set_name("买鱼的小姑娘", ({ "fishbuyer" }) );
	set("gender", "女性" );
	set("age", 15);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",20);
        set("chat_chance", 15);
        set("chat_msg", ({
                "买鱼的小姑娘问道：这鱼怎么卖？\n",
                "买鱼的小姑娘道：八文一斤卖不卖？\n",
        }) );

	setup();
	carry_object("/obj/cloth")->wear();
}
