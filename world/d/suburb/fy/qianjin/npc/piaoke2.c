
inherit NPC;

void create()
{
        set_name("瘦嫖客", ({ "piaoke", "ke"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位干瘦的大嫖客\n");
        set("combat_exp", 50000);
	set_skill("dodge", 100);
	set_skill("unarmed", 120);
        set("chat_chance", 10);
        set("chat_msg", ({
"瘦嫖客回头骂道：下次老子带够银子，看你＂湖上八娇＂从也不从！\n",
		(: random_move :)
        }) );
	
	setup();
	add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
}

