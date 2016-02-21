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
int effective_level() { return 20;}

int learn_bonus()
{
	return 40;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 50;
}

