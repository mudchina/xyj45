// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// fonxanforce.c

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
   return notify_fail("封山派内功\只能用学的或是从运用(exert)中增加熟练度。\n");
