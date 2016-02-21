// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// wugang.c

inherit NPC;

void create()
{
        set_name("吴刚", ({"wu gang","wugang","wu","gang"}));
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个气宇不凡的大汉．");
        set("combat_exp", 100000);
        set("attitude", "peaceful");

        set("eff_dx", 40000);
        set("nkgain", 200);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 80);
        set_skill("literate", 50);
        set_skill("force", 50);   
        set_skill("axe", 100);
        set("per", 27);
        set("max_kee", 500);
        set("max_gin", 200);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 15);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/moon/obj/bigaxe")->wield();
}

int accept_fight(object me)
{
        command("jump");     
        command("say 正好！我砍了半天树，也该换换了。");
        return 1;
}

