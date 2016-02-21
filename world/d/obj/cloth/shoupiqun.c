// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("兽皮裙", ({"shoupi qun", "cloth"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一条兽皮裙。\n");
    set("material", "leather");
    set("unit", "条");
    set("value", 300);
    set("armor_prop/armor", 15);
  }
  setup();
}

