// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("铁匠", ({ "tie jiang", "jiang" }) );
  set("gender", "男性");
  set("age", 35);
  set("combat_exp", 100000+random(20000));
  set("attitude", "heroism");

  set("str", 40);
  set("max_kee", 400);
  set("max_gin", 400);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", 40);
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);
  set_skill("blade", 40);

  setup();

  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/obj/weapon/hammer/hammer")->wield();
}

