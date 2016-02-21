// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
       set_name("鲻太尉", ({"zi taiwei", "zi", "taiwei"}));
        set("long","东海龙宫鲻太尉。\n");
       set("gender", "男性");
       set("age", 40);
        set("per", 15);
        set("str", 25);
        set("con", 25);
        set("cps", 25);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("max_kee", 700);
        set("max_sen", 600);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 15);
        set("mana", 200);
        set("max_mana", 200);
        set("mana_factor", 10);
        set("combat_exp", 200000);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("spells", 100);
        set_skill("force", 100);
        setup();
        carry_object("/d/obj/cloth/magua")->wear();
}

