// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "云靴", ({ "yun xue", "yunxue", "xue" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "一双高腰厚底的云靴。\n");
    set("value", 120);
    set("material", "boots");
    set("armor_prop/dodge", 2);
  }
  setup();
}

