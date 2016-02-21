// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "山鼠",
  "花蛇",
  "灰兔",
  "黑狐",
  "羚羊",
  "野马",
  "野鹿",
  "野驴",
  "山驼",
  "土狍",
  "山鸡",
  "树鸦",
  "猩猩",
});

string *pieces = ({
  "肉干",
  "肉巴",
  "肉条",
  "肉饼",
  "肉板",
});

void create()
{
  string name = names[random(sizeof(names))]
                + pieces[random(sizeof(pieces))];
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
