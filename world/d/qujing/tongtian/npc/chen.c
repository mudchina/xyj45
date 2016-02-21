// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 12.12.1997

inherit NPC;

void create()
{
  set_name("陈长老", ({"chen zhanglao", "chen", "zhanglao"}));
  set("gender", "男性");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 50000);
  set("per", 35);
  set_skill("dodge", 30);
  set_skill("force", 30);
  set_skill("parry", 30);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",500);
  set("max_force",500);
  set("max_mana",500);
  set("force_factor",5);
  setup();

  carry_object("/d/obj/cloth/choupao")->wear();

}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tongtian") == "done")
    return;
  if (! who->query_temp("obstacle/tongtian_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/tongtian","done");
  who->add("combat_exp",i+3000);
  command("chat "+who->query("name")+"通天河救童男女，水宅降鱼精！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
