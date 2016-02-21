// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// tianshan-zhang.c, based on dagou-bang.c

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
	"dodge": -3,
	"damage": 40,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
	"dodge": -5,
	"damage": 45,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招「天山雪崩」砸向$n的$l",
	"dodge": -10,
	"damage": 60,
	"damage_type": "挫伤"
]),
([	"action": "$N一招「峰回路转」，$w左右迂回向$n的$l点去",
	"dodge": -5,
	"damage": 50,
	"damage_type": "挫伤"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 80)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练天山杖法。\n");
	me->receive_damage("kee", 25);
	return 1;
}

