
inherit SKILL;

string *dodge_msg = ({
	"$n一招「阴差阳错」轻轻巧巧地避了开去。\n",
	"只见$n身影一晃，一式「阴风拂面」早已避在七尺之外。\n",
	"$n使出「阴动阳随」，轻轻松松地闪过。\n",
	"$n左足一点，一招「阴气冲天」腾空而起，避了开去。\n",
	"可是$n使一招「阴阳交错」，身子轻轻飘了开去。\n",
	"$n身影微动，已经藉一招「阴鬼叛阎」轻轻闪过。\n",
	"但是$n一招「阴气森森」使出，早已绕到$N身後！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
       if( (string)me->query("gender") != "女性" )
                return notify_fail("九阴身法是只有女子才能练的武功。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练九阴身法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练九阴身法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("ninemoon") + "/ninemoonsteps/" + action;
}

int effective_level() { return 15;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return 20;
}

