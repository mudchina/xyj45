
inherit NPC;

void create()
{
        set_name("狂嫖客", ({ "piaoke", "ke"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位身怀巨金的狂嫖客\n");
        set("combat_exp", 50000);
	set_skill("dodge", 200);
	set_skill("unarmed", 220);
	set("max_force",1000);
	set("force_factor",100);
        set("chat_chance", 3);
        set("chat_msg", ({
"狂嫖客狂笑道：好！！喝了这杯，老子再赏你五十两！\n",
        }) );
	
	setup();
	add_money("gold", 5);
        carry_object(__DIR__"obj/drinkcloth")->wear();
}

