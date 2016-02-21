// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat on 7/5/1997 
inherit NPC;

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

void create()
{
  set_name("斗鸡", ({ "dou ji", "ji" }) );
  set("race", "野兽");
  set("gender", "雄性");
  set("age", 2);
  set("long", "一只雄赳赳的斗鸡。\n");
  set("attitude", "friendly");
  set("max_kee",200+random2(2));
  set("str", 40+random2(2));
  set("spi", 40+random2(2));
  set("cor", 40+random2(2));
  set("con", 40+random2(2));
  set("cor", 40+random2(2));
  set("cps", 40+random2(2));
  set_skill("unarmed", random2(2)+10);
  set_skill("dodge", random2(2)+10);
  set_skill("parry", random2(2)+10);
  set("limbs", ({ "头部", "身体", "尾巴" }) );
  set("verbs", ({ "bite"}) );

  setup();
}

