// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/8/1997

inherit NPC;

void create()
{
  set_name("老王爷", ({"lao wangye", "wangye", "wang", "ye"}));
  set("title", "玉华县");
  set("gender", "男性");
  set("age", 60);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set_skill("unarmed", 60);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set("max_gin",600);
  set("max_kee",600);
  set("max_sen",600);
  set("max_force",600);
  set("max_mana",600);
  set("force_factor",50);
  set("eff_dx",10000);
  set("nkgain",50);
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/yuhua") == "done")
    return;
  if (! who->query_temp("obstacle/yuhua_bang"))
    return;
  if (! who->query_temp("obstacle/yuhua_pa"))
    return;
  if (! who->query_temp("obstacle/yuhua_zhang"))
    return;
  if (! who->query_temp("obstacle/yuhua_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/yuhua","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"豹头山寻得三兵器，竹节山制服九头狮怪！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
