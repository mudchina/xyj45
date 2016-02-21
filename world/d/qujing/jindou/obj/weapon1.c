// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("铁链", ({ "tie lian", "lian", "whip" }) );
  init_whip(35);
  set("unit", "根");
  set_weight(850);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "iron");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}

