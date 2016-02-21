// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit ARMOR;

string *names = ({
  "青柳藤甲",
  "赤柳藤甲",
  "紫柳藤甲",
  "黑柳藤甲",
});

string *ids = ({
  "qingliu teng jia",
  "chiliu teng jia",
  "ziliu teng jia",
  "heiliu teng jia",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "teng jia", "jia", "armor"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 500);
   set("material", "wood");
   set("armor_prop/armor", 30);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
