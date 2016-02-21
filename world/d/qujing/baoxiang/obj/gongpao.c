// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("宫袍", ({"gong pao", "cloth"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件宫袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 300);
    set("armor_prop/armor", 15);
  }
  setup();
}

