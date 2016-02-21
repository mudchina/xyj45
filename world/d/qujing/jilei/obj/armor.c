// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit ARMOR;

string *prefixs = ({
  "镶边",
  "压花",
  "镂花",
  "玉柄",
  "乌心",
});

string *names = ({
  "龙骨甲",
  "虎竹甲",
  "硬藤甲",
  "坚木甲",
  "龟纹甲",
  "灌铅甲",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))],
           ({"armor","jia"}));
  set_weight(20000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 200);
   set("material", "shell");
   set("armor_prop/armor", 30);
   set("armor_prop/dodge", -5);
  }
//  set("no_sell",1);
  setup();
}
