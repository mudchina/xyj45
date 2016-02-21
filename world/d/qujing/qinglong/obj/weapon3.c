// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit FORK;

void create()
{
  set_name("梅花鹿角", ({ "meihualu jiao", "jiao", "fork" }) );
  init_fork(22);
  set("unit", "根");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "bone");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

