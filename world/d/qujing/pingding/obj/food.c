// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "油焖山笋尖",
  "清烧地龙衣",
  "炖汤蘑菇",
  "野栗子糕",
  "黑松子饼",
  "白果仁脆酥",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"food"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "些");
    set("value", 120);
    set("food_remaining", 6);
    set("food_supply", 35);
  }
  set("no_sell",1);
}
