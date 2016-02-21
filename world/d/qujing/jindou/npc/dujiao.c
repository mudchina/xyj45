// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("独角兕大王", ({ "dujiaosi dawang", "dujiaosi", "dawang", "wang" }));
  set("title", "金兜洞");   
  set("long", "一位身材壮实的大块头妖王，头上长着一只角。\n");
  set("gender", "男性");
  set("age", 70);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 1650);
  set("max_gin", 1650);
  set("max_sen", 1650);
  set("force", 1165);
  set("max_force", 1165);
  set("force_factor", 80);
  set("max_mana", 1650);
  set("mana", 1650);
  set("mana_factor", 85);
  set("combat_exp", 1050000);
  set_skill("spells", 90);
  set_skill("dao", 90);
  set_skill("unarmed", 150);
  set_skill("puti-zhi", 150);
  set_skill("dodge", 40);
  set_skill("jindouyun", 80);
  set_skill("parry", 45);
  set_skill("force", 90);
  set_skill("spear", 90);
  set_skill("wuxiangforce", 90);
  set_skill("bawang-qiang", 90);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
  if ("/d/qujing/jindou/obj/zhuoreal"->in_mud())
    carry_object("/d/qujing/jindou/obj/zhuofake");
  else
    carry_object("/d/qujing/jindou/obj/zhuoreal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);

  if (ob)
  {
    ob->set_temp("obstacle/jindou_killed",1);
    call_out ("li_appearing",1,ob);
  }
  message_vision ("\n一阵风吹来，传来天上李老君的声音：牛儿回家也！\n",me);
  message_vision ("\n$N闻声现了原身，果然是一头大青牛。\n",me);
  message_vision ("大青牛沿着李老君声音的方向奔去",me);
  if (fabao)
  {
     message_vision ("，丢下一只$n。\n",me,fabao);
     fabao->move(environment(me));
  }
  else
    message_vision ("。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void li_appearing (object who)
{
  object li = new ("/d/qujing/jindou/npc/lilao");

  li->announce_success (who);
  destruct (li); 
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
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

