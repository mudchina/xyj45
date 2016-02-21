// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("石铲刀", ({ "shichan dao", "dao", "blade" }) );
  init_blade(30);
  set("unit", "把");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 320);
    set("material", "stone");
  }
  setup();
}

