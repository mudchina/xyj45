// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("番木瓜", ({"fanmu gua", "fanmugua", "papaya"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一颗硕大的番木瓜。n");
    set("unit", "颗");
    set("value", 110);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}

