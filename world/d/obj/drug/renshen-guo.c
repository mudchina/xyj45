// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// renshen-guo.c 人参果
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
   add_action("do_eat", "eat");
}

void create()
{
   set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "枚");
     set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
     set("value", 500000);
     set("drug_type", "补品");
   }
  
   set("is_monitored",1);
   setup();
}

int do_eat(string arg)
{
   int howmany;

   object me = this_player();
  
   if (!id(arg)) return notify_fail("你要吃什么？\n");

   howmany = (int)me->query("rsg_eaten");
  
   me->set("food", (int)me->max_food_capacity());

   if((int)me->query("max_force")<10*(int)me->query_skill("force"))
   {
     if( howmany <= 100 ) me->add("max_force",20);
   }
   if((int)me->query("max_mana")<10*(int)me->query_skill("spells"))
   {
     if( howmany <= 100 ) me->add("max_mana",20);
   }

   me->set("rsg_eaten", howmany+1);

   message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快晕了过去。\n" NOR, me);  

   me->set("obstacle/wuzhuang","done");
   me->unconcious();
   destruct(this_object());

   return 1;
}

