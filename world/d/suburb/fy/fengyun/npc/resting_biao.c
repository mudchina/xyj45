
inherit NPC;

void create()
{
        set_name("单身趟子手", ({ "tang", "zhi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位金狮镖局的趟子手。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 10+random(50));
	set_skill("dodge", 10 + random(50));
	set_skill("move",200);
        set("chat_chance", 5);
        set("chat_msg", ({
                "趟子手站起来又坐下，好象很不耐烦．\n",
		"趟子手低声嘀咕道：那么多镖银只有一个人看守，太不保险了．．\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/jinzhuang")->wear();
	if (!random(3))
	carry_object(__DIR__"obj/huopiao");

}

