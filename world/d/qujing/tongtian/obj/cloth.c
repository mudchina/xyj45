// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

string *prefixs = ({
  "厚",
  "薄",
  "粗",
  "细",
});

string *names = ({
  "棉",
  "麻",
  "罗",
  "丝",
});

string *suffixs = ({
  "裤",
  "袄",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"cloth"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 300);
   set("material", "cloth");
   set("armor_prop/armor", 1);
   set("armor_prop/dodge", 1);
  }
//  set("no_sell",1);
  setup();
}
