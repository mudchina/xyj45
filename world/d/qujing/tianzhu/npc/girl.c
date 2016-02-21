// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowcat 12 9 1997

inherit NPC;

void create()
{
  set_name("宫女", ({"gong nu", "nu", "girl"}));
  set("gender", "女性");
  set("combat_exp", 8000);
  set("age", 15);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);

  setup();
  carry_object("/d/qujing/tianzhu/obj/hongqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/jinjie")->wear();
  carry_object("/d/qujing/tianzhu/obj/fengguan")->wear();
}


