// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
  set_name("金睛兽", ({"jinjing shou", "shou"}));
  set("long", "一头双眸放光，银掌玉鞍的金睛兽。\n");
  set("race", "野兽");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "骑");
  set("ride/dodge", 35);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}

