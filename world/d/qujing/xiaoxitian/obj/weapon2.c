// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit FORK;

void create()
{
  set_name("青铜叉", ({ "qingtong cha", "cha", "fork" }) );
  init_fork(40);
  set("unit", "根");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 360);
    set("material", "bone");
  }
  setup();
}

