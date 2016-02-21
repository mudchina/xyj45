// liumai-shenjian.c 六脉神剑

inherit SKILL;

mapping *action = ({
([	"action" : "$N侧身抬臂，右手食指划了个半圈，一式「瓶花落砚」刺向$n的$l",
	"force" : 60,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "瓶花落砚",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌虚托，一式「寒梅吐蕊」，右手小指穿腋疾出，指向$n的胸前",
	"force" : 70,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "寒梅吐蕊",
        "damage_type" : "刺伤"
]),
([	"action" : "$N俯身斜倚，左手半推，右手无名指一式「初杏问酒」，向$n的$l划过",
	"force" : 90,
        "dodge" : 5,
	"lvl" : 0,
	"skill_name" : "初杏问酒",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双目微睁，一式「露草斜阳」，双手幻化出千百个指影，一起刺向$n的$l",
	"force" : 120,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "露草斜阳",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「仰月承霖」，左掌护住丹田，右手大拇指斜指苍天，蓄势捺向$n的$l",
	"force" : 160,
        "dodge" : 15,
	"damage": 10,
	"lvl" : 22,
	"skill_name" : "仰月承霖",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌平托胸前，左手食指一式「叶底留莲」，指向$n的周身大穴",
	"force" : 210,
        "dodge" : 20,
	"damage": 15,
	"lvl" : 36,
	"skill_name" : "叶底留莲",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌翻飞，一式「清风拂桂」，左手拇指指端迸出无数道劲气，射向$n的全身",
	"force" : 270,
        "dodge" : 25,
	"damage": 20,
	"lvl" : 52,
	"skill_name" : "清风拂桂",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「菊圃秋霜」，并指如刃，一束束锐利无俦的剑气，凌虚向$n的$l砍去",
	"force" : 340,
        "dodge" : 30,
	"damage": 30,
	"lvl" : 70,
	"skill_name" : "菊圃秋霜",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「伽叶微笑」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
	"force" : 420,
        "dodge" : 35,
	"damage": 40,
	"lvl" : 90,
	"skill_name" : "伽叶微笑",
        "damage_type" : "刺伤"
]),
([	"action" : "$N左掌竖立胸前，一式「佛祖拈花」，右手食指扣住拇指，轻轻对着$n一弹",
	"force" : 510,
        "dodge" : 50,
	"damage": 10,
	"lvl" : 130,
	"skill_name" : "佛祖拈花",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练六脉神剑必须空手。\n");
	if ((int)me->query_skill("beimin-shengong", 1) < 20)
		return notify_fail("你的北冥神功火候不够，无法学六脉神剑。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练六脉神剑。\n");
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
	level   = (int) me->query_skill("liumai-shenjian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练六脉神剑!\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
