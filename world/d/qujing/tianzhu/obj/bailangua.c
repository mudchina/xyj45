// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("白兰瓜", ({"bailan gua", "bailangua", "gua"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一颗散发清香的白兰瓜。n");
    set("unit", "颗");
    set("value", 120);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}

