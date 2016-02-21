// fanliangyi-dao.c 反两仪刀法

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「混沌一破」，反身一顿，一刀向$n的$l撩去",
	"force" : 120,
	"dodge" : -10,
	"lvl" : 0,
	"skill_name" : "混沌一破",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「太乙生萌」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"force" : 140,
	"dodge" : -10,
	"damage" : 5,
	"lvl" : 20,
	"skill_name" : "太乙生萌",
	"damage_type" : "割伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「两仪合德」，刀锋化作两股斩向$n",
	"force" : 160,
	"dodge" : -5,
	"damage" : 15,
	"lvl" : 40,
	"skill_name" : "两仪合德",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「日月晦明」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"force" : 180,
	"dodge" : 5,
	"damage" : 25,
	"lvl" : 60,
	"skill_name" : "日月晦明",
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「无色无相」，双手持刃拦腰反切，砍向$n的胸口",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 80,
	"skill_name" : "无色无相",
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「万劫不复」，上劈下撩，左挡右开，齐齐罩向$n",
	"force" : 250,
	"dodge" : 15,
	"damage" : 35,
	"lvl" : 100,
	"skill_name" : "万劫不复",
	"damage_type" : "割伤"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候太浅。\n");
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
	level   = (int) me->query_skill("fanliangyi-dao",1);
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
//                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练「反两仪刀法」。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fanliangyi-dao/" + action;
