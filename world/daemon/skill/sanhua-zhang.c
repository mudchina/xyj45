// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// sanhua-zhang.c -散花掌

inherit SKILL;

mapping *action = ({
([	"action" : "$N合掌抱球，一式「春深芳草尽」，双掌变幻吞吐，缓缓推向$n的$l",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "春深芳草尽",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N五指绽开，一式「夏闲独兰馨」，左右掌穿插翻飞，疾向$n的$l拍去",
	"force" : 260,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl" : 20,
	"skill_name" : "夏闲独兰馨",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「秋酣菊霜清」，左掌虚托，右掌乍伸乍合，猛地插往$n的$l",
	"force" : 340,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 40,
	"skill_name" : "秋酣菊霜清",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌血红，一式「冬卧听梅吟」，幻成漫天梅花朵朵，雨点般向$n击去",
	"force" : 420,
        "dodge" : 20,
        "parry" : 30,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "冬卧听梅吟",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="nianhua-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练散花掌必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学散花掌。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练散花掌。\n");
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
        if (!me) me = this_object();
	level   = (int) me->query_skill("sanhua-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练散花掌。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

