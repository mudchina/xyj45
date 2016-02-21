// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("上官阿人", ({"shangguan aren", "aren"}));
  set("gender", "男性");
  set("age", 30);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 20000);
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",12);
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

