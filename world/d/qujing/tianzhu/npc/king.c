// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/9/1997

inherit NPC;

int test_player ();

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "天竺国国王，身披龙袍，神态庄严。\n");
  set("title", "天竺国");
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
    "name" : "朕乃天竺一国之君也，寡人有一公主。",
    "here" : "天竺国也。",
    "天竺" : "天竺国也。",
    "天竺国" : "天竺国也。",
    "公主" : (: test_player :),
    "驸马" : (: test_player :),
    "招亲" : (: test_player :),
    "princess" : (: test_player :),
  ]));
  setup();
  set_temp("no_return",1);
  carry_object("/d/obj/cloth/longpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
}

int test_player ()
{
  object me = this_object();
  object who = this_player();

  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N对$n说道：假驸马道行不足，何以混入禁宫？\n",me,who);
    message_vision ("\n$N对左右吩咐了几句。\n",me);
    message_vision ("几位伺卫官极有礼貌地对$N一点头，拥着$N走出大殿。\n",who);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
    message_vision ("伺卫官走进午门。\n",who);
    return 1;
  }
  if (who->query("obstacle/tianzhu")=="done")
  {
    message_vision ("$N对$n说道：哦，驸马何来？为何不愿西行取经？\n",me,who);
    return 1;
  }
  if (! who->query_temp("obstacle/tianzhu_thrown"))
  {
    message_vision ("$N对$n说道：何许人也居然斗胆混入禁宫？\n",me,who);
    message_vision ("\n$N对左右吩咐了几句。\n",me);
    message_vision ("几位伺位官极有礼貌地对$N一点头，拥着$N走出大殿。\n",who);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
    message_vision ("伺卫官走进午门。\n",who);
    return 1;
  }
  if (who->query_temp("obstacle/tianzhu_killed"))
  {
    object junji = present ("jun ji",environment(me));

    message_vision ("$N对$n说道：朕真糊涂也，误将妖精当爱女！\n",me,who);
    if (! junji)
    {
      message_vision ("\n$N奇怪道：军机大臣何在？\n",me);
      return 1;
    }
    message_vision ("\n$N对$n吩咐了几句。\n",me,junji);
    remove_call_out ("following");
    call_out ("following",5,me,junji,who);
    return 1;
  }
  message_vision ("$N对$n说道：驸马何不后宫拜见公主？\n",me,who);
  return 1;
}

void following (object me, object junji, object who)
{
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

  message_vision ("\n$N点了点头。\n",junji);
  message_vision ("$N对$n说道：可否带陛下去寻公主？\n",junji,who);
  junji->command_function ("follow "+who->query("id"));
  me->command_function ("follow "+who->query("id"));
  me->set("my_saver",who);
  if (taijian1)
    taijian1->command_function ("follow "+who->query("id"));
  if (taijian2)
    taijian2->command_function ("follow "+who->query("id"));
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tianzhu") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/tianzhu","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"天竺国大战兔妖，救回天竺公主！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}

