// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//copy from snowcat :P

#include <ansi.h>

inherit NPC;

void create()
{

  set_name("草头神", ({"caotou shen","shen"}));
  set("gender", "男性");
  set("age", 20+random(20));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "他是二郎神君帐下一千二百个草头神中的一个。\n");
  set("attitude", "peaceful");
  set("combat_exp", 160000);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("force", 100);
  set_skill("spells", 100);
  set_skill("unarmed", 70);
  set("max_gin", 1000);
  set("max_kee", 1000);
  set("max_sen", 1000);
  set("force", 600);
  set("max_force", 600);
  set("force_factor", 30);
  set("mana", 600);
  set("max_mana", 600);
  set("mana_factor", 30);
  set_weight(300000);
  setup();

}

void equalize_gifts (object ob, object me)
{
  // encourage players to have equalized gifts
  ob->set("con",(me->query("spi")+me->query("con"))*2/3);
  ob->set("cor",(me->query("kar")+me->query("cor"))*2/3);
  ob->set("cps",(me->query("per")+me->query("cps"))*2/3);
  ob->set("int",(me->query("str")+me->query("int"))*2/3);
}

int allow_split()
{
  object me = this_object();
  object who = this_player();

  me->set_temp("split",1);
  message_vision ("$N一笑：我一个就够收拾你了。\n",me);
  return 1;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "一千二百个草头神": (: allow_split :),
      ]));
}

int accept_fight (object me)
{
  object ob = this_object();
  equalize_gifts (ob, me);
  ob->setup();
  if (! ob->query_temp("split"))
    return 1;
  if (! ob->query("triplicate"))
  {
    object ob0, ob1, ob2;
    //string str = file_name(ob);
    string str = __DIR__"cao";
    ob0 = present("shen 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("shen 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob1 = new(str);
    ob1->setup();
    ob1->move(environment(ob));
    ob2 = new(str);
    ob2->setup();
    ob2->move(environment(ob));
    message_vision ("“梆梆”几声锣响，从草中跳出几个$N把$n团团围住。\n",ob, me);
    ob->set("kee",ob->query("max_kee")/10*12);
    ob->set("triplicate",1);
    ob1->set("triplicate",1);
    ob2->set("triplicate",1);
    ob1->fight_ob(me);
    ob2->fight_ob(me);
  }
  return 1;
}

