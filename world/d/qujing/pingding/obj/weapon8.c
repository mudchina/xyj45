// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STICK;

void create()
{
  set_name("打狗棍", ({ "daguo gun", "gun", "stick" }) );
  init_stick(25);
  set("unit", "根");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 150);
    set("material", "iron");
  }
  setup();
}

