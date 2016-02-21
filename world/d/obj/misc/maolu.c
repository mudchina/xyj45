// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

string *names = ({
"小毛驴",
"花毛驴",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"mao lu", "lu"}));
  set("race", "野兽");
  set("age", 10);

  set("combat_exp", 10000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "倒骑");
  set("ride/dodge", 10+random(10));
  set_temp("apply/attack", 10);
  set_temp("apply/armor", 20);

  setup();
}

