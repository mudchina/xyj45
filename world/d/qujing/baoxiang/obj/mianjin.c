// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("面筋", ({"mian jin", "mian", "jin"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一绿磁瓶炒面筋。\n");
    set("unit", "绿磁瓶");
    set("value", 90);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}
