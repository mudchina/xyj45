// kuliman.c

inherit NPC;

void create()
{
        set_name("苦力", ({ "kuliman" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "苦力正在为下顿饭而犯愁. \n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
	set_skill("dodge", 10);
        set("chat_chance", 25);
        set("chat_msg", ({
                (:random_move :)
        }) );
	setup();
	add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}
