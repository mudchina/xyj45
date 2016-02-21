// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("美后", ({ "mei hou", "hou", "queen" }));
  set("title", "比丘国");   
  set("long", "一位娇俊无比，貌似观音的王后。\n");
  set("gender", "女性");
  set("age", 17);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 700);
  set("max_force", 700);
  set("force_factor", 60);
  set("max_mana", 700);
  set("mana", 400);
  set("mana_factor", 60);
  set("combat_exp", 410000);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("staff", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jienan-zhi", 50);
  set_skill("lunhui-zhang", 50);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("staff", "lunhui-zhang");
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die ()
{
  object ob = query_temp("my_killer");
  object me = this_object();

  if (ob)
    ob->set_temp("obstacle/biqiu_hou",1);
  message_vision ("\n$N扑在地上现了原身，原是一只狐狸精。\n",me);
  me->set_name("狐狸精", ({"huli jing", "huli", "jing"}));
  ::die();
}

void unconcious ()
{
  die ();
}

