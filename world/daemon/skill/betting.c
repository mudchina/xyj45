// fonxansword.c

inherit SKILL;

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("betting") >=  10)
                return notify_fail("赌之术到了这个程度只能从实赌中提高。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stealing" || usage=="perception";
}

int practice_skill(object me)
{
        if( (int)me->query_skill("betting") >=  10)
                return notify_fail("赌之术到了这个程度只能从实赌中提高。\n");
        return 1;
}

int effective_level() { return 10;}

int learn_bonus()
{
	return -200;
}
int practice_bonus()
{
	return -110;
}
int black_white_ness()
{
	return 0;
}

