// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4.12.1997

inherit NPC;

int move_player();

void create()
{
  set_name("古怪刁钻", ({"guguai diaozuan", "diaozuan", "zuan"}));
  set("gender", "男性");
  set("age", 20);
  set("attitude", "friendly");
  set("combat_exp", 150000);
  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("unarmed",60);
  set_skill("parry",60);
  set_skill("dodge",60);
  setup();

  set("inquiry", ([
       "here": "这儿是豹头山，上面是虎口洞也。\n",
       "豹头山": "豹头山，上面便是虎口洞。\n",
       "虎口洞": (: move_player :),
       "dong": (: move_player :),
       "name": "古怪刁钻。\n",
      ]));
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  carry_object("/d/qujing/baotou/obj/weapon1")->wield();

}

int move_player()
{
  object me = this_object();
  object who = this_player();

  message_vision ("$N看了$n一眼。\n",me,who);
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N摇摇头：道行不够，去不得去不得。\n",me);
    return 1;
  }

  if (! who->query_temp("apply/name") ||
      who->query_temp("apply/name")[0] != "刁钻古怪")
  {
    message_vision ("$N摇摇头：不认得你，不认得你。\n",me);
    return 1;
  }
 
  message_vision ("$N说：$n今天糊涂了也，兄弟我一脚就把你踢进洞里。\n",me,who);
  message_vision ("说着$N飞起一脚，$n顺势往上一跃。\n",me,who);
  who->move("/d/qujing/baotou/dongwai");
  message_vision ("洞口一阵腥风吹来，$N感到一阵突如其来的头晕。\n",who);
  who->set("mana",0);
  return 1;
}

