// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit ARMOR;

string *names = ({
  "乌龟甲",
  "王八甲",
  "千鳞甲",
  "巨蟹壳",
});

string *ids = ({
  "wugui jia",
  "wangba jia",
  "qianling jia",
  "juxie ke",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "jia", "armor"}));
  set_weight(20000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 300);
   set("material", "shell");
   set("armor_prop/armor", 20);
   set("armor_prop/dodge", -5);
  }
  set("no_sell",1);
  setup();
}
