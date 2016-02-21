// five-steps.c

inherit SKILL;

string *dodge_msg = ({
        "但是$n身形有如流水，轻轻一闪，一式水字决中的「抽刀断水」，举重若轻的避开这一击。\n",
        "$n身随意转，脚踩五行，一式五行「木字决」，倏地从木门挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，使出五行身法中的「金字决」，$N这一招扑了个空。\n",
        "却见$n足不点地，幻出五个身影，从火门往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，使出五行「土字决」，土遁到了$N的身后。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query_skill("changelaw") < (int)(me->query_skill("five-steps") / 2) )
                return notify_fail("你对易经的了解还不够高深，无法学习五行身法。\n");
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力太差了，不能练五行身法。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 20;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 10;
}

