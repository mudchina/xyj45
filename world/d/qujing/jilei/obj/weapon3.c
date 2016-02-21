// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit MACE;

void create()
{
  set_name("牛尾锏", ({ "niuwei jian", "jian", "mace" }) );
  init_mace(75);
  set("unit", "根");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "bone");
  }
  setup();
}

