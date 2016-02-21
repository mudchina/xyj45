// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("妖王", ({"yao wang", "wang" }));
  set("title","黄狮精");
  set("gender", "男性");
  set("age", 40);
  set("attitude", "aggressive");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 1000);
  set("max_gin", 1000);
  set("max_sen", 1000);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 70);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 560000);
  set_skill("unarmed", 70);
  set_skill("dodge", 100);
  set_skill("parry", 130);
  set_skill("spells", 70);
  set_skill("force", 70);
  set_skill("staff",130);
  set_skill("gouhunshu", 70);
  set_skill("tonsillit", 70);
  set_skill("ghost-steps", 100);
  set_skill("jinghun-zhang", 70);
  set_skill("lunhui-zhang", 130);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-80000);
  set("nkgain",100);
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baotou/obj/siming")->wield();
  
}

void die()
{
  object me = this_object();
  object where = environment();

  message_vision("只见$N摔倒在地，现了本形。原来是只金毛狮子！\n",me);
  set_name("金毛狮子", ({"yao wang", "wang" }));
  delete("title");
  ::die();
}

void unconcious()
{
  die();
}
