// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 3/31/1997 by snowcat

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("琼瑶豆腐", ({"qiongyao", "doufu", "tofu"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一盘清水碧玉琼瑶豆腐\n");
    set("unit", "盘");
    set("value", 150);
    set("food_remaining", 5);
    set("food_supply", 40);
  }
}

