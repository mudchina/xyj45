// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat

inherit NPC;

void create()
{
  set_name("魏征", ({ "wei zheng", "wei", "zheng" }));
  set("title", "丞相");
  set("gender", "男性");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
  carry_object("/d/kaifeng/obj/sijuan")->wear();
}

void init ()
{
  object me = this_object();
  object who = this_player();

  if (! wizardp(who) &&
      interactive(who))
  {
    object where = environment(me);
    
    if (! where->valid_player(who))
      message_vision ("$N对$n说道：这里是赛场，"+RANK_D->query_respect(who)+
                      "不可随便乱闯也。\n",me,who);
    else 
      command ("hi "+who->query("id")); 
    if (who->query("env/wimpy") > 0)
    {
      who->set("env/wimpy",0);
      message_vision ("$N对$n说道：在这里杀身不伤筋骨，老夫替你将逃命系数(wimpy)置零了。\n",me,who);

    }
  }
}

void die ()
{
  object me = this_object();

  message_vision ("\n地下传来崔判官的声音：$N阳寿未尽！\n",me);
  message_vision ("\n$N颤巍巍地从地上甩袖爬将起来。\n",me);
  set("kee", 3000);
  set("sen", 3000);
}

void unconcious()
{
  die();
}

void accept_fight (object ob)
{
  object me = this_object();

  message_vision ("$N连忙跳开说：老夫筋骨已朽，不打，不打也！\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$N连忙跳开说：老夫筋骨已朽，不打，不打也！\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}
