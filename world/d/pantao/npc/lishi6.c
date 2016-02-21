// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;

void create()
{
  set_name("施肥力士",({ "li shi", "shi" }) );
  set("gender", "男性" );
  set("long", "一位紫绶金章芙蓉冠的大力士，为七大力士之一。\n");
  set("age", 100+random(100));
  set("attitude", "peaceful");
  set("str", 60);
  set("per", 60);
  set("combat_exp",500000);
  set("force",600);
  set("max_force",600);
  set("force_factor", 100);
  set("max_gin", 5000);
  set("max_kee", 5000);
  set("max_sen", 5000);
  set("max_mana", 5000);
  set("mana", 500);
  set("mana_factor", 20);
  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("spear",100);
  set_skill("force",100);
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}
