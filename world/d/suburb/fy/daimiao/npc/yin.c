// 
// 

inherit NPC;
void create()
{
        set_name("银护卫", ({ "yin wei", "yin"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是西方神教五大护卫之一。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
	set_skill("demon-strike",20);
        set_skill("force",50);
	set_skill("demon-steps",40);
	set_skill("dodge", 50);
       	map_skill("unarmed", "demon-strike");
	map_skill("dodge","demon-steps");
        set("force",100);
        set("force_factor",5);
        set("max_force",100);
	create_family("西方神教", 7, "教众");
        set("chat_chance", 1);
        set("chat_msg", ({
                "银护卫向你喝道：今天的口令？？\n",
                "银护卫向你喝道：站住．亮你的腰牌？ 没腰牌就让你血溅当场！\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/blackrobe")->wear();
}

