// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
   if( (int)me->query("bellicosity") < (int)me->query_skill("celestial") * 50 )
     return notify_fail("你的杀气不够，无法领悟更高深的天邪神功\。\n");

   return 1;
}

int practice_skill(object me)
{
   return notify_fail("天邪神功\只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
   return CLASS_D("fighter") + "/celestial/" + func;
}

