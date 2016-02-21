//lingshe_zhangfa.c 灵蛇杖法

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「灵蛇出洞」，手中$w大开大阖扫向$n的$l",
	"force" : 100,
	"dodge": -3,
	"damage": 18,
	"lvl" : 10,
	"skill_name" : "灵蛇出洞",
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招「摇头摆尾」向$n的$l攻去",
	"force" : 140,
	"dodge": -5,
	"damage": 24,
	"lvl" : 20,
	"skill_name" : "摇头摆尾",
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招「灵蛇下涧」砸向$n的$l",
	"force" : 180,
	"dodge": -10,
	"damage": 30,
	"lvl" : 30,
	"skill_name" : "灵蛇下涧",
	"damage_type": "挫伤"
]),
([	"action": "$N一招「灵蛇挺身」，手中$w猛烈扫向$n的$l",
	"force" : 220,
	"dodge": -5,
	"damage": 36,
	"lvl" : 40,
	"skill_name" : "灵蛇挺身",
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招「蛇游蟒走」，$w左右迂回向$n的$l扫去",
	"force" : 260,
	"dodge": -3,
	"damage": 42,
	"lvl" : 50,
	"skill_name" : "蛇游蟒走",
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w一挥，使出一招「蛇缠左右」，忽左忽右扫向$n的$l",
	"force" : 300,
	"dodge": -5,
	"damage": 48,
	"lvl" : 60,
	"skill_name" : "蛇缠左右",
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招「巨蟒下山」，高举手中$w，劈头砸向$n的$l",
	"force" : 340,
	"dodge": -10,
	"damage": 54,
	"lvl" : 80,
	"skill_name" : "巨蟒下山",
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招「灵蛇出洞」，手中$w猛一探，直扫$n的$l",
	"force" : 380,
	"dodge": -3,
	"damage": 60,
	"lvl" : 100,
	"skill_name" : "灵蛇出洞",
	"damage_type": "挫伤"
]),

});

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
//	return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练灵蛇杖法。\n");
	me->receive_damage("qi", 20);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hamagong")) > 10 ) 
	{
	victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
	victim->query_condition("snake_poison"));
        tell_object(victim, HIG "你觉得被击中的地方一阵麻木！\n" NOR );
        tell_object(victim, HIG "原来是被杖头窜出的毒蛇咬了一口！\n" NOR );
	}
}
