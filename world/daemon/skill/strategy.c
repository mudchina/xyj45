// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("strategy", 1);
	if((int)me->query("cor") < s/5) {
		tell_object(me, HIW "由於你的勤学兵法，你的勇气增加了。\n" NOR);
		me->add("cor", 1);
	}
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

