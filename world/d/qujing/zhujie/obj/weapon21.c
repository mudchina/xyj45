// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit SPEAR;

void create()
{
  set_name("双头矛", ({ "shuangtou mao", "mao", "spear" }) );
  init_spear(30);
  set("unit", "把");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 480);
    set("material", "metal");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

