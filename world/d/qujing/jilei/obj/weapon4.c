// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("牛皮鞭", ({ "niupi bian", "bian", "whip" }) );
  init_whip(35);
  set("unit", "根");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 320);
    set("material", "skin");
  }
  setup();
}

