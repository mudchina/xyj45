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
  object guizi;

  if (! who)
    return 0;
  if (! where)
    return 0;
  if (where->query("short") != "坛场")
    return 0;  

  yangli = present("yangli daxian",where);  
  huli = present("huli daxian",where);  
  luli = present("luli daxian",where);  
  king = present("guo wang",where);  
  guizi = present("zhuhong guizi",where);

  if (! yangli || ! huli || ! luli || ! king || ! guizi)
    return 1;
  if (who->query_temp("obstacle/chechi") != "seen_king")
    return 1;
  if (who->query("obstacle/chechi") != "chantai")
    return 1;
  return 2;
}

void init ()
{
  call_out("greet_player",1,this_player());
  add_action ("do_guess","guess");
}

void greet_player (object who)
{
  object me = this_object();

  if (check_valid_player(who) == 2 &&
      ! who->query_temp("obstacle/chechi_greeted2"))
  {
    who->set_temp("obstacle/chechi_greeted2",1);
    message_vision ("几位内官抬着一些东西走来，将朱红柜子布置一番。\n",me);
    message_vision ("内官向北离去。\n\n",me);
    me->command_function("hi "+who->query("id"));
    message_vision ("$N对$n说道：“隔板猜枚，请道出朱红柜子里为何物。”\n",
                    me,who);
  }
}

void display_guess (object me, object who, object guizi,
                    string arg, object luli)
{
  if (! me)
    return;
  if (! who)
    return;

  message_vision ("$N指着柜子说，这里面是"+arg+"吧。\n",who);
}
 
void failing_guess (object me,object who, object where,
                    object guizi, string arg, object luli)
{
  display_guess (me,who,guizi,arg,luli);
  who->start_budy(4,5);
  call_out ("failing",5,me,who,where,guizi,arg,luli);
}

void failing (object me, object who, object where,
              object guizi, string arg, object luli)
{
  string str;
  if (! me)
    return;
  if (! who)
    return;
  if (arg == "宫衣")
  {
    if (random(2))
      str = "桃子";
    else
      str = "道童";
  }
  else if (arg == "桃子")
  {
    if (random(2))
      str = "宫衣";
    else
      str = "道童";
  }
  else if (arg == "道童")
  {
    if (random(2))
      str = "桃子";
    else
      str = "仙衣";
  }
  else
  {
    switch (random(3))
    {
      case 0:
      {
        str = "宫衣";
        break;
      }
      case 1:
      {
        str = "桃子";
        break;
      }
      case 2:
      {
        str = "道童";
        break;
      }
    }
  }
  who->start_budy(3,4);
  call_out ("put_player_in",3,me,who,guizi);
  call_out ("get_player_out",120,me,who,guizi);
  if (luli)
  {
    message_vision ("只见$N苦思冥想，说道：“是"+str+"”。\n\n",luli);
    message_vision ("话音未落，$N打开朱红柜子，却果然是"+str+"。\n\n",me);
  }
  else   
    message_vision ("$N哼地一声打开朱红柜子，里面是"+str+"。\n\n",me);
}

void put_player_in (object me, object who, object guizi)
{
  message_vision ("$N对$n一声冷笑，喊道：“来人！”\n",me,who);
  message_vision ("从宫里早已走出两个内官，将$N左右夹起往柜子里一扔。\n",who);
  me->set_temp("obstacle/chechi","player_in");
  who->move(guizi);
}

void get_player_out (object me, object who, object guizi)
{
  me->set_temp("obstacle/chechi",0);
  who->move(environment(guizi));
  message_vision ("宫里走出两个内官，将$N从柜子里软绵绵地拖了出来。\n\n",who);
  message_vision ("内官重新将朱红柜子布置一番，向北离开。\n",me);
  message_vision ("$N对$n说道：“恕你一回，速猜！”\n",me,who);
}

void success_guess (object me,object who, object where,
                    object guizi, string arg, object luli)
{
  display_guess (me,who,guizi,arg,luli);
  who->start_budy(2,3);
  call_out ("success",2,me,who,where,arg,luli);
}

void success (object me,object who, object where, string arg, object luli)
{
  if (! me)
    return;
  if (! who)
    return;

  message_vision ("$N说道：“开柜！”\n\n",me);
  message_vision ("朱红柜子打开，果然是"+arg+"！\n\n",me);
  who->set("obstacle/chechi","guizi");
  who->save();
  me->set_temp("obstacle/chechi",0);
  message_vision ("$N面露喜色，连声向$n拜道：“请！”\n",me,who);
}

int do_guess (string arg)
{
  object who = this_player();
  object me = this_object();
  object where = environment (me);
  object guizi;
  object luli;
  int status;

  if (! arg)
    return 0;
  if (! who)
    return 0;
  if (! where)
    return 0;
  guizi = present("zhuhong guizi",where);
  if (guizi->query("id") != "zhuhong guizi")
    return 0;
  status = check_valid_player(who);
  if (status == 0)
    return 0;
  luli = present("luli daxian",where);  
  if (luli && luli->query("id") != "luli daxian")
    luli = 0;
  if (me->query_temp("obstacle/chechi")=="busy")
  {
    message_vision ("$N冒冒失失地喊了一声，这里面是"+arg+"！\n",who);
    message_vision ("$N叫道：“住口，这不正猜着吗？”\n",me);
    return 1;
  }
  if (me->query_temp("obstacle/chechi")=="player_in")
  {
    message_vision ("$N癫癫地喊了一声，这里面是"+arg+"！\n",who);
    message_vision ("$N说道：“住口，这里面不还关着人吗？”\n",me);
    return 1;
  }
  me->set_temp("obstacle/chechi","busy");
  if (status == 1 || ! luli)
  {
    failing_guess(me,who,where,guizi,arg,luli);    
  }
  else if (who->query_temp("obstacle/chechi_guizi_times") == 0)
  {
    who->set_temp("obstacle/chechi_guizi_times",1);
    failing_guess(me,who,where,guizi,arg,luli);    
  }
  else if (random(3))
    failing_guess(me,who,where,guizi,arg,luli);    
  else if (arg != "宫衣" && arg != "桃子" && arg != "道童")
    failing_guess(me,who,where,guizi,arg,luli);    
  else
    success_guess(me,who,where,guizi,arg,luli);
  return 1;
}

