// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;

void create()
{
  set_name("皂衣仙女",({ "xian nu", "xian" }) );
  set("gender", "女性" );
  set("long", "一位玉簪珠履绛纱衣的仙女，七大仙女之一。\n");
  set("age", 20+random(10));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",400000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_gin", 4000);
  set("max_kee", 4000);
  set("max_sen", 4000);
  set("max_mana", 4000);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("spear",100);
  set_skill("force",100);
  set_temp("no_return",1);
  setup();
  carry_object("/d/obj/cloth/xianyi")->wear();
}
