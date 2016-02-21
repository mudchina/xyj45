// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("雪饮杯", ({ "snowglass", "glass" }) );
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "杯体碧绿通透，玲珑可爱．\n");
    set("unit", "个");
    set("value", 120);
    set("max_liquid", 100); 
    set("liquid_supply", 80);
  }

  set("liquid", ([
    "type": "water",
    "name": "碧樨茶",
    "remaining": 90,
  ]) );
  setup();
}

