// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("挂毯", ({"gua tan", "guatan", "rug"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件挂毯。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 700);
  }
  setup();
}

