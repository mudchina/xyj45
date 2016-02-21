// tanzhi.c 弹指神通

inherit SKILL;

mapping *action = ({
([  "action" : "$N右指划了个半圈，一式「划天裂地」自上而下划向$n的全身",
    "force" : 320,
    "dodge" : -5,
    "damage": 35,
    "lvl" : 20,
    "skill_name" : "划天裂地",
	"damage_type" : "刺伤"
]),
([  "action" : "$N左掌护胸，一招「我心悠悠」，右指欲举无力指向$n的额头",
    "force" : 280,
    "dodge" : 20,
    "lvl" : 0,
    "skill_name" : "我心悠悠",
    "damage_type" : "刺伤"
]),
([  "action" : "$N双手齐出，一式「千夫所指」，疾指向$n的$l",
    "force" : 190,
    "dodge" : 15,
    "lvl" : 0,
    "skill_name" : "千夫所指",
    "damage_type" : "刺伤"
]),
([  "action" : "$N仰天一叹，一招「弹指人生」，双手幻出重重指影，点向$n的$l",
    "force" : 380,
    "dodge" : -5,
    "damage": 40,
    "lvl" : 50,
    "skill_name" : "弹指人生",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「笑指天南」，左掌蓄式，右指弹出一缕指风点向$n的$l",
    "force" : 240,
    "dodge" : 15,
    "damage": 10,
    "lvl" : 10,
    "skill_name" : "笑指天南",
    "damage_type" : "刺伤"
]),
([  "action" : "$N用出「擎天一指」，蓄集全身力气，一指点向$n的$l",
    "force" : 420,
    "dodge" : -40,
    "damage": 30,
    "lvl" : 80,
    "skill_name" : "擎天一指",
    "damage_type" : "刺伤"
]),

});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练弹指神通必须空手。\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
        return notify_fail("你的碧波神功火候不够，无法学弹指神通。\n");
	if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练弹指神通。\n");
	return 1;
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
    level   = (int) me->query_skill("tanzhi-shentong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
        return notify_fail("你的体力不够，休息一下再练吧。\n");
	if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练弹指神通。\n");
    me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}
