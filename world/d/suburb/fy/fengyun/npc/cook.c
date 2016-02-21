// worker.c

inherit NPC;

void create()
{
        set_name("厨师", ({ "cook" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一个胖胖的的厨师. \n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 30);
        set_skill("parry", 30);
	set_skill("dodge", 30);
	set_skill("sword",30);
        set("chat_chance", 35);
        set("chat_msg", ({
                (:random_move :)
        }) );

	setup();
	add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}
