// horseman.c

inherit NPC;

void create()
{
        set_name("车马店老板", ({ "horseman" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "车马店老板\n");

        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 80);
        set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword",80);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
	setup();
	add_money("silver", 2);
        carry_object("/obj/cloth")->wear();
        
}
