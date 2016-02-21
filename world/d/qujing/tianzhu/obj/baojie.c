// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit FINGER;

void create()
{
  set_name("宝石戒指", ({ "bao jie", "baojie", "ring" }));
  set("weight", 400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("value", 5000);
    set("material", "gold");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}       

