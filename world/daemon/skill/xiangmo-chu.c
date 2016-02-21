//
// xiangmo-chu.c 金刚降魔杵
// Designed by secret(秘密)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N高举手中$w，使出一招「金刚再世」，直劈$n的$l  ",
        "skill_name" : "金刚再世",
        "dodge" : -5,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出「金刚伏魔」，单手舞动$w，一伏身，$w横扫$n的下盘  ",
        "skill_name" : "金刚伏魔",
        "dodge" : 5,
        "parry" : 0,
        "lvl" : 8,
        "damage" : 40,
        "damage_type" : "挫伤",
]),
([      "action" : "$N反身仰面，使出一式「金刚宣法」，双手握$W，一棍直刺$n的$l  ",
        "skill_name" : "金刚宣法",
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 50,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一招「引趣众生」，双手举棍撩向$n的裆部  ",
        "skill_name" : "引趣众生",
        "dodge" : 0,
        "parry" : 10,
        "lvl" : 24,
        "damage" : 60,
        "damage_type" : "挫伤",
]),
([      "action" : "$N舞动手中$w，使出「歌舞阎罗」，顿时罩住$n的全身  ",
        "skill_name" : "歌舞阎罗",
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 32,
        "damage" : 80,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一招「浮游血海」，全身贴地而飞，一棍直捣$n的$l  ",
        "skill_name" : "浮游血海",
        "dodge" : 15,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 100,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一式「驱鬼御魔」，以棍支地，双足飞揣$n的面门  ",
        "skill_name" : "驱鬼御魔",
        "dodge" : 20,
        "parry" : 0,
        "lvl" : 48,
        "damage" : 150,
        "damage_type" : "挫伤",
]),
([      "action" : "$N运力于掌，使出「荡魔除妖」，飞身疾进，手中$w横扫$n的$l  ",
        "skill_name" : "荡魔除妖",
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 56,
        "damage" : 180,
        "damage_type" : "挫伤",
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。\n");
}

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
	level   = (int) me->query_skill("xiangmo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了金刚降魔杵。\n");
	me->receive_damage("qi", 30);
	return 1;
}

