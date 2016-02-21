inherit NPC;
void create()
{
        set_name("陆小凤", ({ "lu", "xiaofeng", "xiao feng" }) );
        set("gender", "男性");
        set("age", 34);
	set("title","心有灵犀一点通");
        set("long",
"四条眉毛的陆小凤\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "陆小凤喃喃道：老刀把子到底是谁？？？\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 580);
	set_skill("move", 150);
        setup();
	carry_object("/obj/cloth")->wear();
}
