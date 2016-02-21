// 
// 

inherit NPC;
void create()
{
        set_name("金护卫", ({ "jin wei", "jin"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是西方神教五大护卫之一。\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
	set_skill("demon-strike",10);
	set_skill("demon-steps",30);
	set_skill("dodge", 40);
	set_skill("force",40);
       	map_skill("unarmed", "demon-strike");
	map_skill("dodge","demon-steps");
        set("force",100);
        set("force_factor",2);
        set("max_force",100);
	create_family("西方神教", 7, "教众");
        set("chat_chance", 10);
        set("chat_msg", ({
                "金护卫向你喝道：今天的口令？？\n",
                "金护卫向你喝道：站住．亮你的腰牌？ 没腰牌就让你血溅当场！\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/blackrobe")->wear();
}

