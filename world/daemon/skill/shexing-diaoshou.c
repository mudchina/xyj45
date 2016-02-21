
// shexing-diaoshou.c 蛇形刁手

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「灵蛇出洞」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
	"force" : 90,
        "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "灵蛇出洞",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N侧身一晃，一式「虎头蛇尾」，左手拿向$n的肩头，右拳打向$n的胸口",
	"force" : 120,
        "dodge" : 10,
	"lvl" : 10,
	"skill_name" : "虎头蛇尾",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「画蛇添足」，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"force" : 130,
        "dodge" : 20,
	"damage": 5,
	"lvl" : 20,
	"skill_name" : "画蛇添足",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚招，右掌直立，一式「杯弓蛇影」，错步飘出，疾拍$n的面门",
	"force" : 160,
        "dodge" : 20,
	"damage": 10,
	"lvl" : 30,
	"skill_name" : "杯弓蛇影",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「蛇行鼠窜」，左拳上格，右手探底突出，抓向$n的裆部",
	"force" : 200,
        "dodge" : 30,
	"damage": 15,
	"lvl" : 38,
	"skill_name" : "蛇行鼠窜",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「蛇磐青竹」，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"force" : 310,
        "dodge" : 40,
	"damage": 25,
	"lvl" : 51,
	"skill_name" : "蛇磐青竹",
        "damage_type" : "内伤"
]),
([	"action" : "$N双手抱拳，一式「万蛇汹涌」，掌影翻飞，同时向$n施出九九八十一招",
	"force" : 380,
        "dodge" : 40,
	"damage": 30,
	"lvl" : 56,
	"skill_name" : "万蛇汹涌",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「白蛇吐信」，拳招若隐若现，若有若无，急急地拍向$n的丹田",
	"force" : 460,
        "dodge" : 40,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "白蛇吐信",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练蛇形刁手必须空手。\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候不够，无法学蛇形刁手。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
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
	level   = (int) me->query_skill("shexing-diaoshou", 1);
        for(i = sizeof(action); i > 0; i--);
}

int practice_skill(object me)
{
	if ((int)me->query("sen") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练蛇形刁手。\n");
	me->receive_damage("sen", 25);
	me->add("force", -5);
	return 1;
}
