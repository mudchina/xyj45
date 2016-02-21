
inherit NPC;

void create()
{
        set_name("大胡子豪客", ({ "haoke", "ke"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位满脸胡子的大豪客\n");
        set("combat_exp", 50000);
	set_skill("dodge", 100);
	set_skill("unarmed", 220);
        set("chat_chance", 1);
        set("chat_msg", ({
"大胡子豪客道：好！够劲儿！\n",
        }) );
	
	setup();
	add_money("gold", 5);
        carry_object("/obj/cloth")->wear();
}

