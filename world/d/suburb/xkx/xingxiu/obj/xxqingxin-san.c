#include <ansi.h>

inherit ITEM;

void create()
{
   set_name("清心散", ({"qingxin san", "san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
      set("value", 1000);
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

   message_vision("$N吃下一包" + name() + "。\n", me);
   if ((int)me->query_condition("xx_poison") > 0) {
      me->apply_condition("xx_poison", 0);
   }

   destruct(this_object());
   return 1;
}
