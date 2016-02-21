// 
// 

inherit NPC;
void create()
{
	string *order=({"上茶", "扫地", "烧饭", "挑水", "砍柴","淘米"});
        set_name((order[random(5)]) +"的道士", ({ "daoshi", "dao"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是岱庙的小道士，正在忙着\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set_skill("unarmed", 5);
	set_skill("demon-steps",3);
	set_skill("dodge", 4);
	set_skill("force",4);
	map_skill("dodge","demon-steps");
        set("force",10);
        set("force_factor",2);
        set("max_force",100);
        set("chat_chance", 10);
        set("chat_msg", ({
                "小道士轻轻的掸了掸身上的尘土．．．\n",
		(: random_move :),
        }) );
	
	setup();
        carry_object(__DIR__"obj/boom");
}

