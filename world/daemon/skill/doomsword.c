// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"群魔乱舞",
		"action":		"$N使一招「白云出岫」，手中$w狂风骤雨般地向$n的$l连攻数剑",
		"dodge":		-200,
		"parry" :		-200,
		"damage":		70,
		"force" : 		200,
		"damage_type":	"刺伤"
	]),
	([	"name":			"厉鬼缠身",
		"action":		"$N身形一转，一招「天绅倒悬」$w斩向$n的$l",
                "dodge":                -200,
                "parry" :               -200,
                "damage":               50,
                "force" :               100,
		"damage_type":	"刺伤"
	]),
	([	"name":			"百鬼夜行",
		"action":		"$N舞动$w，一招「白虹贯日」挟著闪闪剑光刺向$n的$l",
                "dodge":                -200,
                "parry" :               -300,
                "damage":               150,
                "force" :               250,
		"damage_type":	"刺伤"
	]),
	([	"name":			"饿鬼拦路",
		"action":		"$N手中$w一抖，使出「如鬼如魅」往$n的$l刺出一剑",
                "dodge":                -100,
                "parry" :               -100,
                "damage":               50,
                "force" :               150,
		"damage_type":	"刺伤"
	]),
	([	"name":			"鬼影幢幢",
		"action":		"$N手中$w剑光暴长，一招「鬼影幢幢」往$n$l刺去",
                "dodge":                -250,
                "parry" :               -250,
                "damage":               90,
                "force" :               220,
		"damage_type":	"刺伤"
	]),
	([	"name":			"秋坟鬼唱",
		"action":		"$N手中$w直指$n$l，一招「秋坟鬼唱」发出逼人剑气刺去",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法练寒天吹血剑法。\n");

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
		return notify_fail("你的内力或气不够，没有办法练习寒天吹血剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍寒天吹血剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 25;}

string *parry_msg = ({
        "$n不退反进，气走周天，一招「鬼魅无边」，手中的$v狠狠磕开了$N的$w。\n",
	"$n回剑自守，一招「鬼火飘零」，架住了$N的$w。\n",
	"$n一招「群魔乱舞」，手中的$v化作千百把，护住了全身。\n",
	"$n手中的$v自上削下，几乎将$N的$w削成两段。\n",
});

string *unarmed_parry_msg = ({
        "$n使出一招「万炼魔障」，在身前布起了一道铜墙铁壁，封住了$N的攻势。\n",
	"$n一抖手中的$v，使出一招「碧灵魔遁」，手中的$v护住了全身。\n",
	"$n将$v往地上一刺，$v反弹起来，刚好直刺$N的双臂。\n",
	"$n举剑静立，一股内力从剑梢透出，逼开了$N。\n",
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
	return -10;
}

string perform_action_file(string action)
{
        return CLASS_D("fighter") + "/doomsword/" + action;
}


