// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("学童", ({ "xue tong", "tong", "kid" }) );
  set("gender", "男性");
  set("age", 9);
  set("combat_exp", 100+random(10));
  set("attitude", "heroism");

  set("str", 20);
  set("max_kee", 100);
  set("max_gin", 100);
  set("force", 100);
  set("max_force", 100);

  setup();

  carry_object("/d/obj/cloth/linen")->wear();
}

