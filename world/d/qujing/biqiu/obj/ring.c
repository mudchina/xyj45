// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/22/1997

#include <armor.h>

inherit FINGER;

void create()
{
  set_name("紫金戒指", ({ "zijin jiezhi", "jiezhi", "ring" }));
  set("weight", 100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("value", 1000);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}
