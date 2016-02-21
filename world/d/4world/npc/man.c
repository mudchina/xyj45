// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
       set_name("壮汉", ({"man"}));
       set("gender", "男性");
        set("combat_exp", 2000+random(2000));
   set("per", 18);
       set("age", 18+random(10));
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
   set_skill("parry", 15);
        setup();
       add_money("coin", 20+random(50));
   carry_object("/d/obj/cloth/linen")->wear();
}

