// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

string *prefixs = ({
  "花",
  "素",
  "软",
  "细",
});

string *names = ({
  "棉",
  "纱",
  "锦",
  "缎",
});

string *suffixs = ({
  "长裙",
  "短裙",
  "薄裙",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"skirt"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 300);
   set("female_only", 1);
   set("material", "cloth");
   set("armor_prop/armor", 1);
   set("armor_prop/dodge", 1);
  }
//  set("no_sell",1);
  setup();
}
