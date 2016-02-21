// qishang-quan.c -七伤拳
// pal 1997.05.26

inherit SKILL;

mapping *action = ({
([	"action" : "$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l",
	"force" : 180,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "金戈铁马",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出",
	"force" : 200,
	"dodge" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "木已成舟",
        "damage_type" : "内伤"
]),
([	"action" : "$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪",
	"force" : 230,
	"dodge" : 15,
	"damage": 10,
	"lvl" : 20,
	"skill_name" : "水中捞月",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形跃起，一式「火海刀山」，双拳当空击下，势不可挡",
	"force" : 270,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 30,
	"skill_name" : "火海刀山",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一矮，一式「土载万物」，两拳自下而上，攻向$n",
	"force" : 320,
	"dodge" : 10,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "土载万物",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一式「阴风惨惨」，攻向$n的身前身后",
	"force" : 380,
	"dodge" : 25,
	"damage": 25,
	"lvl" : 48,
	"skill_name" : "阴风惨惨",
        "damage_type" : "内伤"
]),
([	"action" : "$N移形换位，步到拳到，一式「阳光普照」，四面八方都是拳影",
	"force" : 450,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 54,
	"skill_name" : "阳光普照",
        "damage_type" : "内伤"
]),
([	"action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸",
	"force" : 530,
	"dodge" : 20,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "七者皆伤",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练七伤拳必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学七伤拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练七伤拳。\n");
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
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练七伤拳。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
