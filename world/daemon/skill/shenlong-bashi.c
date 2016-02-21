// shenlong-bashi 神龙八式
inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「疏影横斜」,左手轻轻一抹，向$n的$l拍去",
	"damage" : 20,
	"parry": 10,
	"force": 100,
        "damage_type" : "瘀伤",
	"skill_name" : "疏影横斜"
]),
([	"action" : "$N鼓气大喝,双掌使一招「五丁开山」，推向$n的$l",
	"damage" : 30,
	"parry": 30,
    "damage_type" : "瘀伤",
	"skill_name" : "五丁开山"
]),
([	"action": "$N顺势使一招「风行草偃」，移肩转身,左掌护面,右掌直击$n",
	"damage" : 40,
	"dodge": 80,
	"parry": 20,
	"force": 200,
	"damage_type": "瘀伤",
	"skill_name" : "风行草偃"
]),
([	"action": "$N退后几步,突然反手一掌,一招「神龙摆尾」，无比怪异地击向$n",
	"damage" : 50,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "瘀伤",
	"skill_name" : "神龙摆尾"
]),
([	"action" : "$N使一式「风卷残云」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
	"damage" : 50,
	"force" : 250,
        "dodge" : 10,
	"lvl" : 30,
        "damage_type" : "瘀伤",
	"skill_name" : "风卷残云"
]),
([	"action": "$N忽的使出「乾坤倒旋」,以手支地,双腿翻飞踢向$n",
	"damage" : 60,
	"dodge": -20,
	"parry": -20,
	"force": 250,
	"damage_type": "瘀伤",
	"skill_name" : "乾坤倒旋"
]),
([	"action": "$N大吼一声，使出「同归于尽」，不顾一切般扑向$n",
	"dodge": -25,
	"parry": -10,
	"damage" : 60,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "同归于尽"
]),
([	"action": "$N深吸一口气,身体涨成球状,猛然流星赶月般直撞向$n",
	"dodge": 80,
	"damage" : 70,
	"parry": -10,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "流星赶月"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练神龙八式必须空手。\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
		return notify_fail("你的神龙心法火候不够，无法学神龙八式.\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学神龙八式。\n");
	if ((int)me->query("max_neili") < 350)
		return notify_fail("你的内力太弱，无法练神龙八式。\n");
	if (2*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("你的神龙心法火
候不够，无法继续学神龙八式。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练神龙八式。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

