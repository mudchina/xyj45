// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("大和尚", ({"heshang"}));
        set("long", "一位大和尚，看起来慈善的很，口里还不停的咏经。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 30+random(10));
        set("combat_exp", 15000);
        set("shen_type", 1);
        set("per", 25);
        set("max_kee", 380);
        set("max_gin", 300);
        set("force", 250);
        set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}

int accept_fight(object me)
{
        command("say 好吧，砌搓技艺，点到为止！\n");
        return 1;
}

