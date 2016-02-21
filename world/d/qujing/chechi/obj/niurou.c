// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("酱牛肉", ({"jiang niurou", "jiangniurou", "niurou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一大盘切得薄薄的酱牛肉片。\n");
    set("unit", "大盘");
    set("value", 250);
    set("food_remaining", 6);
    set("food_supply", 50);
  }
}
