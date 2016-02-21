// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 3/31/1997 by snowcat
#include <weapon.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("粗瓷茶碗", ({ "cuci chawan", "chawan", "wan", "tea" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "这是一只粗瓷茶碗。\n");
    set("unit", "只");
    set("value", 40);
    set("max_liquid", 80); 
  }

  set("liquid", ([
    "type": "tea",
    "name": "淡茶",
    "remaining": 80,
  ]) );
  setup();
}
