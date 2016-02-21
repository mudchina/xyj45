// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("五福道长", ({"dao zhang", "dao"}));
  set("gender", "男性");
  set("combat_exp", 50000);
  set("age", 40);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",10);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);
  set_skill("unarmed", 50+random(90));
  set_skill("dodge", 50+random(90));
  set_skill("parry", 50+random(90));
  set_skill("force", 50+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


