// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;

void create()
{
       set_name("青面鬼", ({"qingmian gui", "gui"}));
       set("gender", "男性");
       set("age", 30);
   set("long", "一个青面鬼，面目狰狞可怕．\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 100);
       set("combat_exp", 35000);
   set_skill("unarmed", 45);
   set_skill("dodge", 45);
   set_skill("whip", 45);
   set_skill("parry", 45);
   set("force", 200);
   set("max_force", 200);
   set("force_factor", 10);
   set("max_kee", 550);
   set("max_sen", 300);
   set("max_mana", 30);
   set("mana", 30);
setup();

        carry_object("/d/obj/weapon/whip/tielian")->wield();
}

