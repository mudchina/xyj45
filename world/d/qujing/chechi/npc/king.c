// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "king" }));
  set("title","车迟国");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 50);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 260000);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("seashentong", 50);
  set_skill("dragonforce", 50);
  set_skill("dragonstep", 50);
  set_skill("dragonfight", 50);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("spells", "seashentong");
  set("eff_dx",30000);
  set("nkgain",180);
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init()
{
  call_out("follow_player",2,this_object(),this_player());
}

int follow_player (object me, object who)
{
  object where = environment (me);
  object yangli = present("yangli",where);
  object huli = present("huli",where);
  object luli = present("luli",where);

  me->set_temp("no_return",1);
  if (where->query("short") != "金銮殿")
    return 1;
  if (! yangli || ! huli || ! luli)
    return 1;
  if (! who)
    return 1;
  if (who->query("obstacle/chechi")=="done")
    return 1;
  if (who->query_temp("obstacle/chechi")!="eaten")
    return 1;
  if (environment(who) != where)
    return 1;
  if (me->query_temp("follow")==who->query("id"))
    return 1;
  message_vision ("\n国王道声：“三位国师请了！”\n",who);
  yangli->set_leader(me);
  huli->set_leader(me);
  luli->set_leader(me);
  message_vision ("\n三大仙凑上前去，跪在国王脚下，低声说着什么。\n\n",me);

  remove_call_out("continue_follow");
  call_out("continue_follow",4,me,who);
  remove_call_out("continue_following");
  call_out("continue_following",8,me,who);
  remove_call_out("following_player");
  call_out("following_player",12,me,who);
  return 1;
}

int continue_follow (object me, object who)
{
  message_vision ("$N吃惊地啊了一声。\n",me);
  message_vision ("$N怒道：“大胆妄徒，竟敢欺骗国师！”\n\n",me);
  if (who && environment(me)==environment(who))
  {
    message_vision ("$N不禁“叭”地一声跪下。\n\n",who);
    who->start_busy (9,10);
  }
  return 1;
}

int continue_following (object me, object who)
{
  object where = environment (me);
  object taijian = present ("tai jian",where);

  if (taijian)
    message_vision ("太监凑上去，低声密语。\n",me);
  message_vision ("$N想了一想，微微点了点头。\n\n",me);
  return 1;
}

int following_player (object me, object who)
{
  object where = environment (me);
  object taijian = present ("tai jian",where);

  if (where->query("short") != "金銮殿")
    return 1;
  if (! who)
    return 1;
  if (who->query("obstacle/chechi")=="done")
    return 1;
  if (who->query_temp("obstacle/chechi")!="eaten")
    return 1;
  if (environment(who) != where)
    return 1;
  if (me->query_temp("follow")==who->query("id"))
    return 1;

  if (taijian)
  {
    message_vision ("$N走上前来，决定跟随$n一起行动。\n\n",taijian,who);
    taijian->set_temp("no_return",1);
    taijian->set_leader(who);
  }
  message_vision ("$N俯视着$n说道：若真是远道仙客，且不妨与三国师一比。\n",
                  me,who);
  message_vision ("\n$N又道：“是死是活，监斩官前见分晓！”\n",me);
  message_vision ("$N决定开始跟随$n一起行动。\n",me,who);
  who->interrupt_me(who,"");
  me->set_temp("follow",who->query("id"));
  me->set_leader(who);
  who->set_temp("obstacle/chechi","seen_king");
  return 1;
}

void announce_success(object who)
{
  int i;

  if (who->query("obstacle/chechi") == "done")
  {
    tell_object (who,"你已经过了这一关，什么都得不到了！\n");
    return;
  }  

  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/chechi","done");
  who->add("combat_exp",i+5000);
  command("chat "+who->query("name")+"车迟国施展圣手，大破妖道！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(5)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
  command("follow none");
}
