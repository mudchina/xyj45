// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }


int valid_learn(object me)
{
   if( (int)me->query_skill("buddhism") <= (int)me->query_skill("chanting") )
     return notify_fail("你的大乘佛法修为还不够高深，无法学习诵经。\n");
   if( (int)me->query("bellicosity") > 100 )
     return notify_fail("你的杀气太重，无法修炼诵经。\n");
   return 1;
}





