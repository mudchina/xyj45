// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit HANDS;

string *names = ({
  "铁手套",
  "铜手套",
});

string *ids = ({
  "tie shou tao",
  "tong shou tao",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "shou tao", "tao", "hands"}));
  set_weight(3000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "副");
   set("value", 200);
   set("material", "metal");
   set("armor_prop/armor", 10);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
