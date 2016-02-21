// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("禅杖", ({ "chan zhang", "zhang", "staff" }) );
  init_staff(35);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 250);
    set("material", "metal");
  }
  setup();
}

