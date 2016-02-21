// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("傲来国武士", ({ "wu shi", "shi", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
   set("long", "傲来国看守城门的武士，威风凛凛的巡视着周围。\n");
        set("combat_exp", 75000);
        set("attitude", "friendly");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);

        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 15);

        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/niupi")->wear();
}


