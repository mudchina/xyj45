// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n一招「金钱撒地」轻轻巧巧地避了开去。\n",
	"只见$n身影一晃，一式「万象争辉」早已避在七尺之外。\n",
	"$n使出「黄花满地」，轻轻松松地闪过。\n",
	"$n左足一点，一招「白柳横坡」腾空而起，避了开去。\n",
	"可是$n使一招「玉树临风」，身子轻轻飘了开去。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练金虹步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
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
	return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("assassin") + "/jinhong-steps/" + action;
}

