// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/6/1997

inherit NPC;

int test_player (object who);

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "钦法国国王，身披龙袍，神态庄严。\n");
  set("title", "钦法国");
  set("gender", "男性");
  set("age", 50);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
    "buddhism" : (: test_player :),
    "monk" : (: test_player :),
    "佛"   : (: test_player :),
    "佛教" : (: test_player :),
    "和尚" : (: test_player :),
    "拜佛" : (: test_player :),
    "入佛" : (: test_player :),
    "入佛门" : (: test_player :),
  ]));
  set("can_sleep",1);
  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void check_hair ()
{
  object me = this_object();

  if (me->query("disable_type") == "<睡梦中>" &&
      me->query_temp("disabled"))
  {
    call_out("check_hair",1);
    return;
  }

  if (me->query_temp("has_said"))
    return;

  message_vision ("$N突然下意识地摸了摸头：天呐，脑袋全剃光了！\n",me);
  message_vision ("$N一阵眩晕，差点摔倒在地！\n",me);
  me->set_temp("has_said",1);
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "jingang")
  {
    message_vision ("$N说道：什么玩意，朕江山已有，岂缺此烂货！\n",me);
    return 0;
  }
  if (! query_temp("has_said"))
  {
    message_vision ("$N说道：正好，朕要杀尽一万和尚！\n",me);
    me->kill_ob(who);
    return 1;
  }
  if (who->query_temp("obstacle/qinfa_cut_times")<4)
  {
    message_vision ("$N说道：你个臭佛儿！朕要杀尽一万和尚！\n",me);
    me->kill_ob(who);
    return 1;
  }
  command ("thank "+who->query("id"));
  me->set_temp("has_book",ob->query("name"));
  remove_call_out ("reading");
  call_out ("reading",3);
  return 1;
}

void reading ()
{
  object me = this_object();
  string book = me->query_temp("has_book");

  if (! living (me))
  {
    message_vision ("$N翻了翻白眼。\n",me);  
    return;
  }
  if (! book)
  {
    message_vision ("$N沉思片刻。\n",me);  
    return;
  }

  message_vision ("$N捧起"+book+"，聚精会神地读了起来。\n",
                  me);  
  me->set_temp("can_believe",1);
  if (random(4))
  {
    remove_call_out ("reading");
    call_out ("reading",3);
  }
}

int test_player (object who)
{
  object me = this_object();
  who = this_player();
  if (! me->query_temp("can_believe")) 
  {
    message_vision ("$N说道：朕要杀尽一万和尚！\n",me);
    return 1;
  }    
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N说道：你，道行不足，岂可多嘴！\n",me);
    return 1;
  }    
  if (who->query_temp("obstacle/qinfa_cut_times")<4)
  {
    message_vision ("$N说道：朕曾被僧所谤也。\n",me);
    return 1;
  }    
  if (who->query("obstacle/qinfa") == "done")
  {
    message_vision ("$N说道：久仰久仰！\n",me);
    return 1;
  }    
  message_vision ("$N沉默几许，点了一下头。\n\n",me);
  remove_call_out ("saying1");
  call_out ("saying1",3,who);  
  return 1;
}

void saying1 (object who)
{
  object me = this_object();
  message_vision ("$N说道：朕曾因僧谤了朕，许天愿要杀一万和尚做圆满。\n\n",me);
  remove_call_out ("saying2");
  call_out ("saying2",3,who);  
}

void saying2 (object who)
{
  object me = this_object();
  message_vision ("$N说道：不期今夜归依，教朕等为僧。\n\n",me);
  remove_call_out ("saying3");
  call_out ("saying3",5,who);  
}

void saying3 (object who)
{
  object me = this_object();
  message_vision ("$N说道：如今发都剃落了，朕愿入佛门。\n\n",me);
  remove_call_out ("saying4");
  call_out ("saying4",5,who);  
}

void saying4 (object who)
{
  object me = this_object();
  message_vision ("$N又说道：此乃天意也。\n\n",me);
  remove_call_out ("announce_success");
  call_out ("announce_success",5,who);  
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/qinfa") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/qinfa","done");
  who->add("combat_exp",i+3000);
  command("chat "+who->query("name")+"灭法国劝朕归依佛门，朕改国号为钦法国！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
