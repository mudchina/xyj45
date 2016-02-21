// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("犀牛皮衣", ({"xiniu piyi", "piyi", "yi"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value", 5000);
    set("material", "leather");
    set("armor_prop/armor", 25);
  }
  setup();
}

