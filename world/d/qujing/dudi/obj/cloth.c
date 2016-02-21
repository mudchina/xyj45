// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

string *prefixs = ({
  "粉色",
  "翡红",
  "淡黄",
  "鹅黄",
  "紫花",
});

string *names = ({
  "柳絮",
  "丝绒",
  "罗纱",
  "细纱",
  "麻纱",
});

string *suffixs = ({
  "护裙",
  "战裙",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"skirt", "cloth"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 200);
   set("material", "leather");
   set("armor_prop/armor", 2);
   set("armor_prop/dodge", 2);
  }
//  set("no_sell",1);
  setup();
}
