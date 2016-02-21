// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;

void create()
{
       set_name("崔珏", ({"cui jue", "cui"}));
   set("title", "判官");
       set("gender", "男性");
   set("long", "崔判官原是阳世为官，因广积阴德，死后被封为阴间判官．\n");
       set("age", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
       set("max_kee", 600);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 650);
       set("max_force", 600);
       set("force_factor", 20);
       set("max_mana", 600);
       set("mana_factor", 10);
       set("combat_exp", 100000);
       set_skill("unarmed", 50);
       set_skill("dodge", 40);
       set_skill("parry", 70);
   set_skill("sword", 80);
        set_skill("force", 50);

setup();

        carry_object("/d/obj/cloth/choupao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/obj/weapon/sword/panguanbi")->wield();
}

