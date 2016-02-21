// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("轮转王", ({"lunzhuan wang", "wang"}));
       set("title", "阴间十王之");
       set("gender", "男性");
       set("age", 70);
   set("class", "youling");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 900);
       set("max_gin", 700);
       set("max_sen", 700);
       set("force", 450);
       set("max_force", 400);
       set("force_factor", 30);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
       set("combat_exp", 660000);
   set_skill("spells", 100);
   set_skill("gouhunshu", 100);
       set_skill("unarmed", 139);
       set_skill("dodge", 139);
       set_skill("parry", 130);
   set_skill("force", 100);
   set_skill("tonsillit", 100);
   map_skill("spells", "gouhunshu");
   map_skill("force", "tonsillit");
   create_family("阎罗地府", 1, "你好");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}

