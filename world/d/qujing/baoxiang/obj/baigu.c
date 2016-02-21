// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat dec 19 1997

inherit ITEM;

void create()
{
  set_name("白骨", ({"bai gu", "gu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一堆白骨。\n");
    set("unit", "堆");
    set("material", "bone");
  }
  setup();
}

