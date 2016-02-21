// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit SHIELD;

string *names = ({
  "牦牛皮",
  "水牛皮",
  "野象皮",
  "公鹿皮",
  "豺皮",
});

string *ids = ({
  "maoniu pi",
  "shuiniu pi",
  "yexiang pi",
  "gonglu pi",
  "chai pi",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"pi", "shield"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 500);
   set("material", "leather");
   set("armor_prop/armor", 15);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
