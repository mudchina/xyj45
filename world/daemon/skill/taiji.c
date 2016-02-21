// taiji.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N双手圆转，使出一招「揽凤尾」，对准$n的$l击出",
		"dodge":		-30,
		"parry":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左掌虚晃，右掌画了一个圆弧，一招「单鞭」便往$n的$l招呼过去",
		"dodge":		-20,
		"parry":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「白鹤亮翅」，双掌成圆弧形提起，圆转着向$n的$l击出",
		"dodge":		-20,
		"parry":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左掌阳、右掌阴，使出一招「手挥琵琶」，双掌慢慢向$n的$l合拢",
		"dodge":		-20,
		"parry":		40,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练太极拳法必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 13;}

string *parry_msg = ({
        "$n一招「提手上势」，圆弧形击$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n脚走太极，一招「搂膝勾步」，逼得$N后退三步。\n",
        "$n以守为攻，一招「进步搬拦锤」，猛击$N握$w的手腕。\n",
        "$n一招「如封似闭」，双掌不断圆转，引得$N不由自主地转了一圈。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「十字手」，逼得$N中途撤招。\n",
        "$n脚走阴阳、以静制动，一招「抱虎归山」，把$N带出好远。\n",
        "$n左掌阴、右掌阳，使出太极拳的「起手式」，轻而易举地将$N封于尺外。\n",
        "$n双掌齐出，使出太极拳最后一式「单鞭和太极」，$N的功势入泥牛入海，消失得无影无踪。\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return -20;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("wudang") + "/taiji/" + action;
}
