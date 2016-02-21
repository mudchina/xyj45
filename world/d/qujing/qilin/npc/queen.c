// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 11/6/1997 by snowcat

inherit NPC;

void create()
{
  string dir;
  set_name("金圣宫", ({"jinsheng gong", "gong", "queen"}));
  set("title", "朱紫国");
  set("gender", "女性");
  set("age", 28);
  set("per", 26);
  set("rank_info/respect", "娘娘");
  set("combat_exp", 100000);
  set_skill("snowsword", 30);
  set_skill("sword", 30);
  set_skill("dragonfight", 30);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set_skill("spells", 30);
  set_skill("dragonstep", 30);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_gin", 500);
  set("max_kee", 500);
  set("max_sen", 500);
  set("force", 500);
  set("max_force", 500);
  set("mana", 500);
  set("max_mana", 500);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void test_player (object who);

void init()
{
  test_player (this_player());
  ::init();
}

void test_player (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/zhuzi") == "done")
    return;
  if (! who->query_temp("obstacle/zhuzi_cured"))
    return;
  if (! who->query_temp("obstacle/zhuzi_killed"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/zhuzi","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"朱紫国施神力治愈万岁，解救金圣宫于三年久祸！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
  command ("thank");
  call_out ("leaving",2);
}

void leaving ()
{
  object me = this_object();

  command("bow");
  command("southeast");
  destruct (me);
}
