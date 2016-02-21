// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STICK;

void create()
{
  set_name("烧火棍", ({ "shaohuo gun", "gun", "stick" }) );
  init_stick(15);
  set("unit", "根");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 100);
    set("material", "bone");
  }
  setup();
}

