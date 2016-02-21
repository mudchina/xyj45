// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
  set_name("王后", ({"wang hou", "hou", "queen"}));
  set ("long", "钦法国王后，面容雅丽，举止端庄。\n");
  set("title", "钦法国");
  set("gender", "女性");
  set("age", 30);
  set("combat_exp", 100000);
  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_sen", 500);
  set("max_kee", 500);
  set("max_force", 500);
  set("force", 100);
  set("force_factor", 4);

  set("can_sleep",1);
  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
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
