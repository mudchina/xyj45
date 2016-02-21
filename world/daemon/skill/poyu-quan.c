// poyu-quan.c 劈石破玉拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N右脚立定、左脚虚点，一式「起手式」，左右手一高一低，击向$n的$l",
	"force" : 180,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "起手式",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左脚虚踏，全身右转，一招「石破天惊」，右拳猛地击向$n的$l",
	"force" : 200,
	"dodge" : 10,
	"lvl" : 10,
	"skill_name" : "石破天惊",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手大开大阖，宽打高举，使一招「铁闩横门」，双拳向$n的$l打去",
	"force" : 220,
	"dodge" : 15,
	"lvl" : 20,
	"skill_name" : "铁闩横门",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左掌圈花扬起，屈肘当胸，右手虎口朝上，一招「千斤坠地」打向$n的$l",
	"force" : 260,
	"dodge" : 20,
	"lvl" : 30,
	"skill_name" : "千斤坠地",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「傍花拂柳」，上身前探，双拳划了个半圈，击向$n的$l",
	"force" : 300,
	"dodge" : 25,
	"lvl" : 40,
	"skill_name" : "傍花拂柳",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双拳划弧，一记「金刚挚尾」，掌出如电，一下子切到$n的手上",
	"force" : 360,
	"dodge" : 0,
	"lvl" : 50,
	"skill_name" : "金刚挚尾",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N施出「封闭手」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
	"force" : 420,
	"dodge" : 35,
	"lvl" : 60,
	"skill_name" : "封闭手",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左脚内扣，右腿曲坐，一式「粉石碎玉」，双拳齐齐捶向$n的胸口",
	"force" : 540,
	"dodge" : 40,
	"lvl" : 80,
	"skill_name" : "粉石碎玉",
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「劈石破玉拳」必须空手。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候不够，无法学「劈石破玉拳」。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练「劈石破玉拳」。\n");
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
	level   = (int) me->query_skill("poyu-quan");
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
//                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练「劈石破玉拳」。\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"poyu-quan/" + action;
