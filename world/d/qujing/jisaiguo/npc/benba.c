// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/1/1997

inherit NPC;

void create()
{
  set_name("奔波儿灞", ({ "benboer ba", "ba" }) );
  set("gender", "男性" );
  set("title", "鲇鱼怪");
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "heroism");
  set("combat_exp", 50000);

  set_skill("force",  50); 
  set_skill("spells", 50); 
  set_skill("unarmed",50);
  set_skill("sword",  50);
  set_skill("dodge",  50);
  set_skill("parry",  50);

  set("max_gin", 500);
  set("eff_gin", 500);
  set("gin", 500);
  set("max_kee", 500);
  set("eff_kee", 500);
  set("kee", 500);
  set("max_sen", 500);
  set("eff_sen", 500);
  set("sen", 500);
  set("force", 600);
  set("max_force", 600);
  set("mana", 600);
  set("max_mana", 600);
  set("force_factor", 10);

  setup();

  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void init()
{
  remove_call_out("autofight");
  call_out("autofight",random(2)+1,this_object(),this_player());
}

void autofight(object me, object ob)
{
  if (me->is_fighting())
    return;
  if (! interactive(ob))
    return;
  if (! living(me))
    return;
   
  message_vision("$N对$n叫道：哪来的鸟贼人！\n",me,ob);
  message_vision("$N揪住$n就打了起来！\n\n",me,ob);

  me->fight_ob(ob);
  ob->fight_ob(me);
  remove_call_out("check_result");
  call_out("check_result", 1, me, ob);  
}

int check_result(object me, object ob)
{
  int my_max_kee, his_max_kee;

  if (! ob)
    return 1;
  if (environment(ob)!=environment(me))
    return 1;

  my_max_kee  = me->query("max_kee");
  his_max_kee = ob->query("max_kee");

  if (me->is_fighting())
  {
    call_out("check_result",1, me, ob);
    return 1;
  }

  if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
  {
    object tie;

    message_vision ("$N战战兢兢，口叫饶命。\n",me);

    ob->set_temp("obstacle/jisaiguo/bbeb1",1);
    if (ob->query_temp("obstacle/jisaiguo/letter"))
      return 1;
    if (ob->query_temp("obstacle/jisaiguo/bbeb2")==0)
      return 1;

    ob->set_temp("obstacle/jisaiguo/letter",1);
    tie = new ("/d/qujing/jisaiguo/obj/tie");
    tie->move(ob);
    message_vision ("$N交给$n一封帖。\n",me,ob);
    
  }

  if (( (int)ob->query("kee")*100/his_max_kee)<=50)
  {
    message_vision ("$N对$n发出一阵狂笑。\n",me,ob);
  }

  return 1;  
}

void die()
{
  object me = this_object();
  object fish = new("/d/qujing/jisaiguo/obj/fish");

  fish->set_name("鲇鱼",({"fish"}));
  fish->move(environment(me));
  message_vision("\n$N慢慢地倒下，现形为一条鲇鱼。\n",me);
  destruct(me);
}
