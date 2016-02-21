// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("老奶奶", ({ "lao nainai", "lao", "nainai", "queen" }));
  set("title", "压龙洞");   
  set("long", "一位扭腰摆臀的压龙洞妖后，身上隐隐地发出狐臭。\n");
  set("gender", "女性");
  set("age", 86);
  set("attitude", "heroism");
  set("per", 12);
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 700);
  set("max_force", 700);
  set("force_factor", 40);
  set("max_mana", 700);
  set("mana", 700);
  set("mana_factor", 40);
  set("combat_exp", 750000);
  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 55);
  set_skill("puti-zhi", 55);
  set_skill("dodge", 50);
  set_skill("jindouyun", 50);
  set_skill("parry", 55);
  set_skill("force", 50);
  set_skill("wuxiangforce", 50);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/pingding_laonai_killed",1);
    call_out ("taishang_appearing",1,ob);
  }
  message_vision ("\n$N翻倒在地现了真身，是一只狐狸精。\n",me);
  message_vision ("狐狸精死了。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void taishang_appearing (object who)
{
  object taishang = new ("/d/qujing/pingding/npc/taishang");

  taishang->announce_success (who);
  destruct (taishang); 
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


