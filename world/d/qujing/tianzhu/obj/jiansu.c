// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("小煎酥", ({"jian su", "jiansu", "su"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一盘香脆的小煎酥。\n");
    set("unit", "盘");
    set("value", 140);
    set("food_remaining", 4);
    set("food_supply", 25);
  }
}

