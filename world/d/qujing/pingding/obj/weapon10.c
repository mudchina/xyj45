// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit MACE;

void create()
{
  set_name("刺槐锏", ({ "cihuai jian", "jian", "mace" }) );
  init_mace(25);
  set("unit", "根");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 240);
    set("material", "wood");
  }
  setup();
}

