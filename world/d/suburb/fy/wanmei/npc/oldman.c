inherit NPC;
void create()
{
        set_name("满脸风霜的老人", ({ "oldman", "old man", "man" }) );
        set("gender", "男性");
        set("age", 74);
        set("long",
"这是一个满脸风霜的老人，但他双目有神，太阳穴高高隆起！\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "满脸风霜的老人用袖子远远地一拂，你立刻感到透不过气来。\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 50);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);
	set_skill("move", 150);

        set_skill("doomforce", 50);
        set_skill("doomstrike", 50);
        set_skill("doomsteps", 5);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");


        setup();
	carry_object("/obj/cloth")->wear();
}
