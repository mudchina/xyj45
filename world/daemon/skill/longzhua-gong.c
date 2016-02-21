// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// longzhua-gong.c -龙爪功

inherit SKILL;

mapping *action = ({
([	"action" : "在呼呼风声中，$N使一招「捕风式」，双手如钩如戢，插向$n的$l",
	"force" : 100,
	"dodge" : 5,
	"lvl"   : 0,
	"skill_name" : "捕风式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N猛地向前跃出，一招「捉影式」，两腿踢出，双手抓向$n的面门",
	"force" : 110,
	"dodge" : 5,
	"damage": 5,
	"lvl"   : 6,
	"skill_name" : "捉影式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N双手平伸，十指微微上下抖动，一招「抚琴式」打向$n的$l",
	"force" : 120,
	"dodge" : 10,
	"damage": 5,
	"lvl"   : 12,
	"skill_name" : "抚琴式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N左手上拦，右手内挥，一招「击鼓式」击向$n胸口",
	"force" : 140,
	"dodge" : 10,
	"damage": 10,
	"lvl"   : 18,
	"skill_name" : "击鼓式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N右手虚握，左手掌立如山，一招「批亢式」，猛地击向$n的$l",
	"force" : 160,
	"dodge" : 15,
	"damage": 10,
	"lvl"   : 24,
	"skill_name" : "批亢式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N腾步上前，左手护胸，右手探出，一招「掏虚式」击向$n的裆部",
	"force" : 190,
	"dodge" : 15,
	"damage": 15,
	"lvl"   : 30,
	"skill_name" : "掏虚式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N双手平提胸前，左手护住面门，一招「抱残式」右手推向$n的$l",
	"force" : 220,
	"dodge" : 20,
	"damage": 15,
	"lvl"   : 35,
	"skill_name" : "抱残式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N两手胸前环抱，腋下含空，五指如钩，一招「守缺式」插向$n的顶门",
	"force" : 260,
	"dodge" : 20,
	"damage": 20,
	"lvl"   : 40,
	"skill_name" : "守缺式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N右腿斜插$n二腿之间，一招「抢珠式」，上手取目，下手反勾$n的裆部",
	"force" : 300,
	"dodge" : 25,
	"damage": 20,
	"lvl"   : 45,
	"skill_name" : "抢珠式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N一手虚指$n的剑诀，一招「夺剑式」，一手劈空抓向$n手中的长剑",
	"force" : 350,
	"dodge" : 25,
	"damage": 25,
	"lvl"   : 50,
	"skill_name" : "夺剑式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「拿云式」使$n进退两难",
	"force" : 400,
	"dodge" : 30,
	"damage": 25,
	"lvl"   : 55,
	"skill_name" : "拿云式" ,		
	"damage_type" : "内伤"
]),
([	"action" : "$N前脚着地，一手顶天成爪，一手指地，一招「追日式」劲气笼罩$n的全身",
	"force" : 460,
	"dodge" : 40,
	"damage": 30,
	"lvl"   : 60,
	"skill_name" : "追日式" ,		
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练龙爪功必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学龙爪功。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练龙爪功。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
        if (!me) me = this_object();
	level   = (int) me->query_skill("longzhua-gong",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练龙爪功。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

