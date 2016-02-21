// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

string *names = ({
  "黑罴皮",
  "棕熊皮",
  "青狈皮",
  "豺皮",
  "牦牛皮",
  "猛犸皮",
});

string *ids = ({
  "heipi pi",
  "zongxiong pi",
  "qingbei pi",
  "chai pi",
  "maoniu pi",
  "mengma pi",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "pi", "cloth"}));
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
