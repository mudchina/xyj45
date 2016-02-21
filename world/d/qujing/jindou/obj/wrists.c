// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit WRISTS;

string *names = ({
  "铁护腕",
  "铜护腕",
});

string *ids = ({
  "tie hu wan",
  "tong hu wan",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "hu wan", "wan", "wrists"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 200);
   set("material", "metal");
   set("armor_prop/armor", 9);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
