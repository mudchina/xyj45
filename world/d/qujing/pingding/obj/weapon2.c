// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("花竺剑", ({ "huazhu jian", "jian", "sword" }) );
  init_sword(35);
  set("unit", "把");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "iron");
  }
  setup();
}

