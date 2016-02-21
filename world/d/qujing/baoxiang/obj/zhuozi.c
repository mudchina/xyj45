// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("镂空木桌", ({"zhuo zi", "zhuozi", "table"}));
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一张镂空木桌。\n");
    set("material", "wood");
    set("unit", "张");
    set("value", 1200);
  }
  setup();
}

