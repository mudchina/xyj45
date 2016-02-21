// 
// 

inherit NPC;
void create()
{
        set_name("迎客僧", ({ "welcome bonze","bonze" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("age", 32);
        set("str", 26);
        set("cor", 14);
        set("cps", 29);
        set("int", 25);
        set("long", "一个笑咪咪的兴国禅寺的迎客僧。\n");
        set("combat_exp", 1000+random(5000));
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set("chat_chance", 1);
        set("chat_msg", ({
                "迎客僧向你双掌合十，笑道：欢迎，欢迎！\n",
		"迎客僧说道：施主，你的杀气太重了！\n",
		"迎客僧笑道：施主，施主，一定要多多施舍！\n",
	}) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
