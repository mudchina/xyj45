// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "烤肉块",
  "烤肉巴子",
  "烤头肉",
  "烤腿子肉",
  "烤胸脯肉",
  "烤坐臀肉",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一大块烤熟的兽肉。\n");
    set("unit", "大块");
    set("food_remaining", 6);
    set("food_supply", 35);
    set("value",50);
  }
}
