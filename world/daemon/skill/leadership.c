// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("leadership", 1);
	if((int)me->query("per") < s/5) {
		tell_object(me, HIW "由於你的勤学用人之技，你的魅力提高了。\n" NOR);
		me->add("per", 1);
	}
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

