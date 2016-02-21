// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "蛇肉",
  "鹿脯",
  "熊掌",
  "驼峰",
  "马腿",
  "驴肺",
  "狼肝",
  "狍肉",
  "虎唇",
  "狮鼻",
  "豹舌",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一大块晒干的兽肉。\n");
    set("unit", "大块");
    set("food_remaining", 6);
    set("food_supply", 35);
  }
}

