// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit SHIELD;

string *names = ({
  "犀牛皮盾",
  "熊皮盾",
  "象皮盾",
  "虎皮盾",
});

string *ids = ({
  "xiniupi dun",
  "xiongpi dun",
  "xiangpi dun",
  "hupi dun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "dun", "shield"}));
  set_weight(10000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 500);
   set("material", "skin");
   set("armor_prop/armor", 20);
   set("armor_prop/dodge", -3);
  }
  set("no_sell",1);
  setup();
}
