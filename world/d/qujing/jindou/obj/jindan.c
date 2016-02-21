// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snowcat 4/25/97

#include <weapon.h>

inherit THROWING;

void create()
{
  set_name("●金丹砂●", ({"jindan sha", "sha"}));
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一些闪闪发光的金丹砂。\n");
    set("unit", "些");
    set("base_unit", "颗");
    set("base_weight", 40);
    set("base_value", 1);
  }
  set("is_monitored",1);
  set_amount(18);
  set("rigidity",100);
  init_throwing(500);
  setup();
}

