// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 11/22/1997
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("辣味牛汤", ({ "lawei niutang", "niutang", "tang" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一碗红呼呼的辣味牛肉汤。\n");
    set("unit", "碗");
    set("value", 160);
    set("food_remaining", 4);
    set("food_supply", 25);
  }
}

