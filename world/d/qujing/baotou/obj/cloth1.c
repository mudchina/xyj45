// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

string *names = ({
  "花豹皮",
  "白虎皮",
  "黑虎皮",
  "金狮皮",
  "卷毛狮皮",
  "山猫皮",
});

string *ids = ({
  "huabao pi",
  "baihu pi",
  "heihu pi",
  "jinshi pi",
  "juanmao pi",
  "shanmao pi",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"pi", "cloth"}));
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
