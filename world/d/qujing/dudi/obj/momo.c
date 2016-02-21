// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "白面馍馍",
  "玉米馍馍",
  "薯面馍馍",
  "豆沙馍馍",
  "邓沙馍馍",
  "菜馅馍馍",
  "笋馅馍馍",
  "葱花馍馍",
  "香油馍馍",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"mo mo", "mo"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只蒸得松软松软的馍馍。\n");
    set("unit", "只");
    set("food_remaining", 6);
    set("food_supply", 35);
  }
}

