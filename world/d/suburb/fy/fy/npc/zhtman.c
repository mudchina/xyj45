// zhtman.c

inherit NPC;

void create()
{
        set_name("澡堂老板", ({ "zhtman" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一个澡堂老板\n");

        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("sword",50);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
	setup();
	add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}
