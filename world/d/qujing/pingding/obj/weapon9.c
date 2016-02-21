// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("牛角刃", ({ "niujiao ren", "ren", "dagger" }) );
  init_dagger(20);
  set("unit", "把");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "iron");
  }
  setup();
}

