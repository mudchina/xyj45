// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("辟寒大王", ({ "pihan dawang", "dawang" }));
  set("title", "玄英洞");   
  set("long", "一位妖怪，鼻子上长着一根角。");
  set("gender", "男性");
  set("age", 50);
  set("attitude", "heroism");
  set("per", 29);
  set("max_kee", 1400);
  set("max_gin", 1400);
  set("max_sen", 1400);
  set("force", 1400);
  set("max_force", 1400);
  set("force_factor", 90);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 80);
  set("combat_exp", 640000);
  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 90);
  set_skill("dragonfight", 85);
  set_skill("dodge", 10);
  set_skill("jindouyun", 70);
  set_skill("sanban-axe", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("wuxiangforce", 70);
  set_skill("axe", 85);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "sanban-axe");
  map_skill("axe", "sanban-axe");
  set("env/wimpy", 50);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/axe")->wield();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob)
  {
    ob->set_temp("obstacle/jinping_pi1_killed",1);
    call_out ("fuling_appearing",1,ob);
  }
  message_vision ("\n$N扑倒在地，还原为一头犀牛。\n",me);
  message_vision ("\n天空四木禽星一闪，犀牛被一道光捉了去！\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void fuling_appearing (object who)
{
  object prince = new ("/d/qujing/jinping/npc/fuling");

  prince->announce_success (who);
  destruct (prince); 
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

