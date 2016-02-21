//
// riyue-lun.c 日月轮法
// Designed by secret(秘密)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「破竹势」，抡起手中的$w向$n的$l砸去  ",
        "skill_name" : "破竹势",
        "force" : 120,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「隐山谷势」，双肩一沉，舞动手中$w向$n的$l横扫  ",
        "skill_name" : "隐山谷势",
        "force" : 160,
        "dodge" : -20,
        "parry" : 20,
        "lvl" : 8,
        "damage" : 55,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「隐微势」，就地一滚，手中自下而上撩向$n的$l  ",
        "skill_name" : "隐微势",
        "force" : 200,
        "dodge" : -20,
        "parry" : 10,
        "lvl" : 16,
        "damage" : 60,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「擒纵势」，身形起伏之际$w扫向$n的$l  ",
        "skill_name" : "擒纵势",
        "force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "lvl" : 24,
        "damage" : 65,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「圆满势」，$w如离弦之箭般直捣$n的$l  ",
        "skill_name" : "圆满势",
        "force" : 280,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 32,
        "damage" : 70,
        "damage_type" : "挫伤",
]),
([      "action" : "$N跃入半空，使一招「月重辉势」，高举$w敲向$n的$l  ",
        "skill_name" : "月重辉势",
        "force" : 320,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 40,
        "damage" : 75,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「捉月势」，斜举手中$w击向$n的$l  ",
        "skill_name" : "捉月势",
        "force" : 360,
        "dodge" : -15,
        "parry" : 15,
        "lvl" : 48,
        "damage" : 80,
        "damage_type" : "挫伤",
]),
([      "action" : "$N提一口真气，使出「显吉祥」，$w扫向$n的头部  ",
        "skill_name" : "显吉祥",
        "force" : 400,
        "dodge" : -20,
        "parry" : 15,
        "lvl" : 56,
        "damage" : 100,
        "damage_type" : "挫伤",
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
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
	level   = (int) me->query_skill("riyue-lun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够,练不了日月轮法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
