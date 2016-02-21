
inherit NPC;

void create()
{
        set_name("趟子手", ({ "tang", "zhi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位体态轻盈的趟子手。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
	set_skill("dodge", 100);
        set("chat_chance", 5);
        set("chat_msg", ({
                "趟子手又在一人多高的梅花桩上练习了一遍。\n",
        }) );
	
	setup();
	add_money("silver", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
}

