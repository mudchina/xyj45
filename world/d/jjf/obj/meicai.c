// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 5-15-97 pickle

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("梅菜扣肉", ({"meicai kourou", "kourou", "rou"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一盘香喷喷地梅菜扣肉。\n");
    set("unit", "盘");
    set("value", 0);
    set("food_remaining", 5);
    set("food_supply", 40);
  }
}

