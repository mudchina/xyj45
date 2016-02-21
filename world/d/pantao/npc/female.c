// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;

void create()
{
  string *names = ({ "仙女", "仙妃", "仙子", });
  string name = names[random(sizeof(names))];

  set_name(name,({ "xian" }) );
  set("gender", "女性" );
  set("long", "一位玉簪珠履绛纱衣的"+name+"。\n");
  set("age", 20+random(10));
  set("attitude", "peaceful");
  set("str", 40);
  set("per", 40);
  set("combat_exp",300000);
  set("force",400);
  set("max_force",400);
  set("force_factor", 100);
  set("max_gin", 3000);
  set("max_kee", 3000);
  set("max_sen", 3000);
  set("max_mana", 3000);
  set("mana", 300);
  set("mana_factor", 20);
  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("spear",100);
  set_skill("force",100);
  set("chat_chance",5);
  set("chat_msg",({(: random_move :)}));
  setup();
  carry_object("/d/obj/cloth/xianyi")->wear();
}
