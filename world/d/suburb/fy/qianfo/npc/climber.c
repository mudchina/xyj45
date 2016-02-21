// 
// 

inherit NPC;
void create()
{
        set_name("登山者", ({ "climber" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long", "一个累得不行了的登山者，正在歇脚．\n");
        set("combat_exp", 600);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_fight(object me)
{
        command("say 佛门净地，不可放肆！\n");
        return 0;
}
