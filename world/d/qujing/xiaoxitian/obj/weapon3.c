// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("法锤", ({ "fa chui", "chui", "hammer" }) );
  init_hammer(25);
  set("unit", "把");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "metal");
  }
  setup();
}

