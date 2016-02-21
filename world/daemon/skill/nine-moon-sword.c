
#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"阴魂不散",
		"action":		"$N使一招「阴魂不散」，手中$w剑光暴长，向$n的$l刺去",
		"dodge":		50,
		"force":		170,
		"damage_type":	"刺伤"
	]),
	([	"name":			"阴气森森",
		"action":		"$N剑随身转，一招「阴气森森」罩向$n的$l",
		"dodge":		-70,
		"force":		200,
		"damage_type":	"刺伤"
	]),
	([	"name":			"阴云迭起",
		"action":		"$N舞动$w，一招「阴云迭起」挟著无数剑光刺向$n的$l",
		"dodge":		-40,
		"damage":		90,
		"damage_type":	"刺伤"
	]),
	([	"name":			"阴曹地府",
		"action":		"$N手中$w龙吟一声，祭出「阴曹地府」往$n的$l刺出数剑",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
	([	"name":			"阴阳两仪",
		"action":		"$N手中$w剑光暴长，一招「阴阳两仪」往$n$l刺去",
		"dodge":		60,
		"damage":		120,
		"damage_type":	"刺伤"
	]),
	([	"name":			"阴日阳月",
		"action":		"$N手中$w化成一道光弧，直指$n$l，一招「阴日阳月」发出虎哮龙吟刺去",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;
       if( (string)me->query("gender") != "女性" )
                return notify_fail("九阴赤炼剑法是只有女子才能练的武功。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练九阴赤炼剑法。\n");
       if( (string)me->query_skill_mapped("force")!= "nine-moon-force")
                return notify_fail("九阴赤炼剑法必须配合九阴心经才能练。\n");
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
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习九阴赤炼剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍九阴赤炼剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}

int effective_level() { return 8;}

string *parry_msg = ({
        "$n使出九阴赤炼剑中「阴风狂吼」，将$N手中的$w引偏了出去。\n",
	"$n踏坎位，入生门，手中的$v往上一撩，架住了$N手中的$w。\n",
	"$n向$N左侧进一步，手中的$v顺着$N的$w滑下，急削$N握$w的手指。\n",
	"$n手中的$v一抖，一招「九朵赤炼」，$v幻出九条剑影，锁住了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n气透剑尖，一招「阴风刺骨」，强劲的剑气直取$N的咽喉。\n",
	"$n反手一剑，$v象一条孽龙，直扑$N的手腕。\n",
	"$n右脚后踏一步，$v递左手，右手向$N虚按，一股劲力使$N抬不起手。\n",
	"$n转身，$v突然从腋下刺出，一招「沙地赤蝎」，刺向$N的手腕。$N慌忙撤招自保。\n",
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

