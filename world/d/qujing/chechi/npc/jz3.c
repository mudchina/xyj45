// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("监斩官", ({"jianzhan guan", "guan"}));
  set("gender", "男性");
  set("combat_exp", 200000);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",100);
  set("max_gin",1000);
  set("max_kee",1000);
  set("max_sen",1000);
  set("max_force",1200);
  set("max_mana",1200);
  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("force", 90);
  set_skill("spells", 90);
  setup();
  carry_object("/d/qujing/chechi/obj/gongpao")->wear();
  carry_object("/d/qujing/chechi/obj/dao")->wield();
}

// 0: invalid place; 1: invalid condition; 2: valid
int check_valid_player (object who)
{
  object me = this_object();
  object where = environment (me);
  object yangli;
  object huli;
  object luli;
  object king;
  object youguo;

  if (! who)
    return 0;
  if (! where)
    return 0;
  if (where->query("short") != "祈雨场")
    return 0;  

  yangli = present("yangli daxian",where);  
  huli = present("huli daxian",where);  
  luli = present("luli daxian",where);  
  king = present("guo wang",where);  
  youguo = present("da youguo",where);

  if (! yangli || ! huli || ! luli || ! king || ! youguo)
    return 1;
  if (who->query_temp("obstacle/chechi") != "seen_king")
    return 1;
  if (who->query("obstacle/chechi") != "guizi")
    return 1;
  return 2;
}
void init ()
{
  call_out("greet_player",1,this_player());
  add_action ("do_enter","enter");
}

void greet_player (object who)
{
  object me = this_object();

  if (check_valid_player(who) == 2 &&
      ! who->query_temp("obstacle/chechi_greeted3"))
  {
    who->set_temp("obstacle/chechi_greeted3",1);
    me->command_function("hi "+who->query("id"));
    message_vision ("$N对场外喝道：“添柴。”早有内官上前将大火挑旺。\n",me);
    message_vision ("内官退下。\n\n",me);
    message_vision ("$N对$n说道：“请下油锅，与国师双武洗。”\n",me,who);
  }
}

int do_enter (string arg)
{
  object who = this_player();
  object me = this_object();
  object where = environment (me);
  object youguo;
  object yangli;
  int status;

  if (! arg)
    return 0;
  if (! who)
    return 0;
  if (! where)
    return 0;
  youguo = present("da youguo",where);
  if (youguo->query("id") != "da youguo")
    return 0;
  if (present(arg,where) != youguo)
    return 0;
  status = check_valid_player(who);
  yangli = present("yangli daxian",where);  
  if (yangli && yangli->query("id") != "yangli daxian")
    yangli = 0;
  if (status == 0)
    return 0;
  who->set_temp("obstacle/chechi_invalid_enter",0);
  if (status == 1 || ! yangli)
  {
    who->set_temp("obstacle/chechi_invalid_enter",1);
    call_out ("failing_enter",1,me,who,where,youguo,yangli);
  }
  else if (who->query_temp("obstacle/chechi_youguo_times") == 0)
  {
    who->set_temp("obstacle/chechi_youguo_times",1);
    call_out ("failing_enter",1,me,who,where,youguo,yangli);    
  }
  else if (random(3))
  {
    call_out ("failing_enter",1,me,who,where,youguo,yangli);    
  }
  else
  {
    call_out ("success_enter",1,me,who,where,youguo,yangli);
  }
  return 1;
}

void display_enter (object me, object who,
                    object youguo, object yangli)
{
  if (! me)
    return;
  if (! who)
    return;
  if (yangli)
  {
    message_vision ("$N一个起身，纵入热浪翻滚的大油锅。\n\n",yangli);
    yangli->move(youguo);
  }
  message_vision ("$N一个起身，纵入热浪翻滚的大油锅。\n\n",who);
  who->move(youguo);
}
 
void failing_enter (object me,object who, object where,
                    object youguo, object yangli)
{
  display_enter (me,who,youguo,yangli);
  call_out ("failing",30+random(10),me,who,where,yangli);
}

void failing (object me,object who, object where, object yangli)
{
  int i;
  if (! me)
    return;
  if (! who)
    return;
  if (environment(who)->query("name")!="大油锅")
    return;
  message_vision ("$N在油面上绝望地抓了一把。\n\n",who);
  message_vision ("只见"+who->name()+"在油面上绝望地抓了一把。\n\n",me);
  message_vision ("$N见况不妙，大喊：“来人！”。\n",me);
  message_vision ("早已从后面冲上几个内官用铁爪篱捞出$n。\n",me,who);
  who->move(where);
  if (yangli)
  {
    yangli->move(where);
    message_vision ("$N费力地翻身出锅落地。\n",yangli);
  }
  who->unconcious();
  i = who->query("combat_exp");
  if ((i<200000) || wizardp(who))
  {
    if (random(3) || who->query_temp("obstacle/chechi_invalid_enter")==0)
      return;
    who->delete_temp("last_damage_from");
    who->set_temp("death_msg","被滚油烹死了。\n");
    who->die();
    who->save();
  }
}

void success_enter (object me,object who, object where,
                    object youguo, object yangli)
{
  display_enter (me,who,youguo,yangli);
  call_out ("success",40+random(10),me,who,where,yangli);
}

void success (object me,object who, object where, object yangli)
{
  if (! me)
    return;
  if (! who)
    return;
  if (environment(who)->query("name")!="大油锅")
    return;

  who->move(where);
  if (yangli)
  {
    message_vision ("$N在油面上绝望地探出头来。\n\n",yangli);
    message_vision ("$N急忙大喊：“来人，国师完也！”。\n",me);
    message_vision ("几个内官赶来用铁爪篱捞出$n。\n",me,yangli);
    yangli->move(where);
    message_vision ("$N皮焦肉烂，已不成形。\n\n",yangli);
    yangli->die();
  }
  message_vision ("$N兴奋地点点头，向$n拜道：“请！”\n",me,who);
  remove_call_out("king_announce_success");
  call_out("king_announce_success",2,where,who);
}

void king_announce_success(object where, object who)
{
  object king;

  if (! who)
    return;
  king = present ("guo wang",where);
  if (king && king->query("id") != "guo wang")
    king = 0;
  if (! king)
    king = new ("/d/qujing/chechi/npc/king");
  tell_room (where,king->name()+
             "大悟道：“果然是兽精！”\n\n");
  tell_room (where,king->name()+
             "又道：“寡人糊涂，竟尊其为国师，岂不殃民祸国！”\n");
  king->announce_success (who);
  call_out("daxians_die",5,where);
}

void daxians_die (object where)
{
  object yangli;
  object huli;
  object luli;
  yangli = present("yangli daxian",where);  
  if (yangli && yangli->query("id") == "yangli daxian")
    yangli->die();
  huli = present("huli daxian",where);  
  if (huli && huli->query("id") == "huli daxian")
    huli->die();
  luli = present("luli daxian",where);  
  if (luli && luli->query("id") == "luli daxian")
    luli->die();
}
