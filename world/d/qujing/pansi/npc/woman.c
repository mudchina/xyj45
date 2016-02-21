// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/6/1997

inherit NPC;

int test_player (object me);

void create()
{
  set_name("断肠妇人", ({"duanchang furen", "furen", "woman"}));
  set("long", "身着重孝的妇人。\n");
  set("gender", "女性");
  set("age", 36);
  set("per", 18);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 2000);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",12);
  set("inquiry", ([
        "钱":   (: test_player :),
        "纸钱": (: test_player :),
        "黄钱": (: test_player :),
      ]));

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

int test_player (object me)
{
  object who = this_player();

  if (who->query("combat_exp")<10000)
  {
    me->command_function("shake");
    return 1;
  }  

/*
  if (who->query("obstacle/pansi") == "done")
  {
    me->command_function("shake");
    return 1;
  }  
*/

  me->command_function("nod");
  call_out ("give_money",2,me,who);
  return 1;
}

void give_money (object me, object who)
{
  object money = new ("/d/qujing/pansi/obj/money");

  money->move(me);
  me->command_function ("give "+who->query("id")+" money");
}
