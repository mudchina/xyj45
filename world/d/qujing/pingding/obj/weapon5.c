// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("青石锤", ({ "qingsho chui", "chui", "hammer" }) );
  init_hammer(30);
  set("unit", "把");
  set_weight(1500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "stone");
  }
  setup();
}

