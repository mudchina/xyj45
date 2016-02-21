// huashan-zhangfa.c 华山掌法

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「白云出岫」，双掌间升起一团淡淡的白雾，缓缓推向$n的$l",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "白云出岫",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N并指如剑，一式「白虹贯日」，疾向$n的$l戳去",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "白虹贯日",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「云断秦岭」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "云断秦岭",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌隐隐泛出青气，一式「青松翠翠」，幻成漫天碧绿的松针，雨点般向$n击去",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "青松翠翠",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形往上一纵，使出一式「天绅倒悬」，双掌并拢，笔直地向$n的$l插去",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage": 50,
	"lvl" : 40,
	"skill_name" : "天绅倒悬",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形一变，使一式「无边落木」，双掌带着萧刹的劲气，猛地击往$n的$l",
	"force" : 380,
        "dodge" : 25,
        "parry" : 25,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "无边落木",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「高山流水」，左掌凝重，右掌轻盈，同时向$n的$l击去",
	"force" : 420,
        "dodge" : 30,
        "parry" : 30,
	"damage": 70,
	"lvl" : 60,
	"skill_name" : "高山流水",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N突地一招「金玉满堂」，双掌挟着一阵风雷之势，猛地劈往$n的$l",
	"force" : 460,
        "dodge" : 30,
        "parry" : 35,
	"damage": 80,
	"lvl" : 70,
	"skill_name" : "金玉满堂",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「风伴流云」，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
	"force" : 500,
        "dodge" : 40,
        "parry" : 45,
	"damage": 90,
	"lvl" : 80,
	"skill_name" : "风伴流云",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「烟雨飘渺」，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪",
	"force" : 540,
        "dodge" : 45,
        "parry" : 50,
	"damage": 110,
	"lvl" : 90,
	"skill_name" : "烟雨飘渺",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练华山掌法必须空手。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("你的紫霞神功火候不够，无法学华山掌法。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练华山掌法。\n");
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
	level   = (int) me->query_skill("huashan-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 40)
		return notify_fail("你的内力不够练华山掌法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huashan-zhangfa/" + action;
