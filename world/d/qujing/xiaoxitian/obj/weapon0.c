// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("七齿耙", ({ "qichi pa", "pa", "rake" }) );
  init_rake(35);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "metal");
  }
  setup();
}

