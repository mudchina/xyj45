// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("清白老酒壶", ({"jiu hu", "jiuhu", "hu"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "一个用来装清白老酒的酒壶。\n");
     set("unit", "个");
     set("value", 200);
     set("max_liquid", 15);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "清白老酒",
        "remaining": 15,
        "drunk_supply": 12,
      ]));
}

