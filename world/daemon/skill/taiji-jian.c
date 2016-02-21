// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// taiji-jian.c 太极剑

inherit SKILL;

mapping *action = ({
([	"action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 25,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 30,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 170,
	"dodge" : 15,
	"damage" : 40,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l",
	"force" : 190,
	"dodge" : 10,
	"damage" : 50,
        "lvl" : 19,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
	"force" : 240,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
	"force" : 280,
	"dodge" : 5,
	"damage" : 70,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「却步抽剑」，左脚跃步落地，$w回抽，反手勾向$n的$l",
	"force" : 300,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 59,
	"damage_type" : "刺伤"
]),
([	"action" : "$N右腿半屈般蹲，一招「如封似闭」，剑尖虚指，转身撩向$n的$l",
	"force" : 330,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
	"force" : 380,
	"dodge" : -5,
	"damage" : 115,
        "lvl" : 99,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("taiji-quan", 1) < 20)
		return notify_fail("你的太极拳火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
        if (!me) me = this_object();
	level   = (int) me->query_skill("taiji-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练太极剑法。\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}
