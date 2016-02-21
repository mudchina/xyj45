// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「古松挂月」，对准$n的$l「呼」地一拳",
		"dodge":		-40,
		"parry":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N扬起拳头，一招「傲雪冬梅」便往$n的$l招呼过去",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左手虚晃，右拳「孤崖听涛」往$n的$l击出",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N步履一沉，左拳拉开，右拳使出「荒山虎吟」击向$n$l",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练柳家拳法必须空手。\n");
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
int effective_level() { return 7;}

string *parry_msg = ({
        "$n一招「瞒天过海」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右拳虚幌，左拳一招「暗渡陈仓」，逼得$N后退三步。\n",
        "$n以守为攻，一招「反客为主」，猛击$N握$w的手腕。\n",
        "$n一招「金蝉脱壳」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「瞒天过海」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「釜底抽薪」，攻$N之必救。\n",
        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
        "$n双拳齐出，使出一招「一箭双雕」，$N的功势入泥牛入海，消失得无影无踪。\n",

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

