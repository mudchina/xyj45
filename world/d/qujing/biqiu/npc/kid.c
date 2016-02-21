// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("小儿", ({"xiao er","kid"}));
  set("gender", "男性");
  set("combat_exp", 1);
  set("age", 2);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 1);

  setup();
}

