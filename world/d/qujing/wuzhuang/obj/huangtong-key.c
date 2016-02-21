// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// huangtong-key.c 

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIY "黄铜钥匙" NOR, ({"huangtong key", "key"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("long", "一把黄铜钥匙。\n");
   }
  
   set("is_monitored",1);
   setup();
}


