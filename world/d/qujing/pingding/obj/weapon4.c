// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit AXE;

void create()
{
  set_name("开山斧", ({ "kaishan fu", "fu", "axe" }) );
  init_axe(35);
  set("unit", "把");
  set_weight(1100);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "iron");
  }
  setup();
}

