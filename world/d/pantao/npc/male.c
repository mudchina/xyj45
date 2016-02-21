// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;

void create()
{
  string *names = ({ "仙官", "仙将", "仙卿", });
  string name = names[random(sizeof(names))];

  set_name(name,({ "xian" }) );
  set("gender", "男性" );
  set("long", "一位紫绶金章芙蓉冠的"+name+"。\n");
  set("age", 100+random(100));
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
  set("chat_chance",5);
  set("chat_msg",({(: random_move :)}));
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}
