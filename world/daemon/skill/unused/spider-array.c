// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// sword.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
   object *member;

   member = leader->query_team();
   if( sizeof(member) != 8 )
     return notify_fail("灵蛛剑阵共需八人，少一个多一个都不行。\n");
   message_vision( HIG "$N率领众人四下站定八个方位，组成了「灵蛛剑阵」！\n" NOR, leader);
   return 1;
}
