// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// damo-jian.c 达摩剑

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「万事随缘往」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 120,
        "dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "万事随缘往",
	"damage_type":	"刺伤"
]),
([	"action":"$N错步上前，使出「来去若梦行」，剑意若有若无，$w淡淡地向$n的$l挥去",
	"force" : 140,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "来去若梦行",
	"damage_type":	"割伤"
]),
([	"action":"$N一式「浮世沧桑远」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "浮世沧桑远",
	"damage_type":	"割伤"
]),
([	"action":"$N纵身轻轻跃起，一式「轮回法舟轻」，剑光如轮疾转，霍霍斩向$n的$l",
	"force" : 180,
        "dodge" : 10,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "轮回法舟轻",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w中宫直进，一式「水月通禅寂」，无声无息地对准$n的$l刺出一剑",
	"force" : 220,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "水月通禅寂",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式「鱼龙听梵音」，对准$n的$l斜斜击出",
	"force" : 260,
        "dodge" : 5,
	"damage": 45,
	"lvl" : 44,
	"skill_name" : "鱼龙听梵音",
	"damage_type":	"刺伤"
]),
([	"action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「千里一苇去」刺向$n的$l",
	"force" : 320,
        "dodge" : 5,
	"damage": 55,
	"lvl" : 52,
	"skill_name" : "千里一苇去",
	"damage_type":	"刺伤"
]),
([	"action":"$N合掌跌坐，一式「禅心顿自明」，$w自怀中跃出，如疾电般射向$n的胸口",
	"force" : 380,
        "dodge" : 5,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "禅心顿自明",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="xiuluo-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
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
	level   = (int) me->query_skill("damo-jian",1);
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
		return notify_fail("你的体力不够练达摩剑。\n");
	me->receive_damage("kee", 25);
	return 1;
}
