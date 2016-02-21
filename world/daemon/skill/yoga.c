// iron-cloth.c

inherit SKILL;
#include <ansi.h>
void skill_improved(object me)
{
        int s;

        s = me->query_skill("yoga", 1);
        if( (int)me->query("dur") < s/5) {
                tell_object(me, HIW "由於你勤练瑜珈，你的耐力提高了。\n" NOR);
                me->add("dur", 1);
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

