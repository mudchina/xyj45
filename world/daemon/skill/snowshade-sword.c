// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「回光幻电」，手中$w幻一条疾光刺向$n的$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出矛山雪影剑中的「风霜碎影」，$w连挥剑光霍霍斩向$n的$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「残阳照雪」，纵身飘开数尺，手中$w斩向$n的$l",
		"dodge":		-30,
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w中宫直进，一式「冰谷初虹」对准$n的$l刺出一剑",
		"dodge":		-40,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N纵身一跃，手中$w一招「长空雷隐」对准$n的$l斜斜刺出一剑",
		"dodge":		-40,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w凭空一指，一招「断石狼烟」刺向$n的$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练雪影剑法。\n");


	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习雪影剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍雪影剑法。\n");
	return 1;
}
int effective_level() { return 11;}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 30;
}

string *parry_msg = ({
        "结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return CLASS_D("taoist") + "/snowshade-sword/" + action;
}


