// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("水酒罐", ({"jiu guan", "jiuguan", "guan"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "一个装水酒的大酒罐。\n");
     set("unit", "个");
     set("value", 160);
     set("max_liquid", 25);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "水酒",
        "remaining": 25,
        "drunk_supply": 6,
      ]));
}

