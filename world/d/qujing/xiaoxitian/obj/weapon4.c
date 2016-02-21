// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("紫云剑", ({ "ziyun jian", "jian", "sword" }) );
  init_sword(45);
  set("unit", "把");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 420);
    set("material", "metal");
  }
  setup();
}

