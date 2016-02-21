// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// kanmen.c, created by mes
// updated 6-20-97 pickle

inherit NPC;

void create()
{
  set_name("看门妖", ({"kanmen yao","kanmen","kanmenyao","yao","monster"}));
  set("long","一个看门的小妖，张牙舞爪的，挺怕人。\n");
  set("gender", "男性");
  set("cor", 25);
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set_skill("unarmed", 40);
  set_skill("parry", 25+random(15));
  set_skill("dodge", 25+random(15));
  set_skill("blade", 40);
  setup();
  add_money("silver", 2);
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/linen")->wear();
}
