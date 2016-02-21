// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，轻轻一纵，一招「醉仙望月」，轻而易举的避开这一击。\n",
        "$n身随意转，一式「仙人敬酒」，往旁窜开数尺，躲了开去。\n",
        "$n身形往上拔起，一招「把酒飞仙」，一个转折落在数尺之外。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力太差了，不能练醉仙望月步。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 10;}

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

string perform_action_file(string action)
{
        return CLASS_D("yinshi") + "/zuixian-steps/" + action;
}


