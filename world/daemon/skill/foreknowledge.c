// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("foreknowledge", 1);
	if( (int)me->query("kar") < s/5) {
		tell_object(me, HIW "由於对占卜学的更深一步的理解，你的运气提高了。\n" NOR);
		me->add("kar", 1);
	}
}

int learn_bonus()
{
	return 10;
}

int practice_bonus()
{
	return 0;
}

int black_white_ness()
{
	return 0;
}

