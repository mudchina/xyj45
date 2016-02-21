// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("老妇", ({"lao fu","fu"}));
  set("gender", "女性");
  set("age", 60);
  set("combat_exp", 1000);
  set("per", 19);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("dodge", 30);
  set("max_sen",100);
  set("max_gee",100);
  set("max_gin",100);
  set("force",100);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",4);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
