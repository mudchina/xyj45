//jiuyin-baiguzhao.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N左爪虚晃，右爪蓄力，一招「勾魂夺魄」直插向$n的$l",
    "force" : 320,
    "dodge" : 10,
    "damage": 30,
    "lvl"   : 0,
    "skill_name" : "勾魂夺魄" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N双手连环成爪，爪爪钩向$n，「九子连环」已向$n的$l抓出",
    "force" : 380,
    "dodge" : 20,
    "damage": 45,
    "lvl"   : 20,
    "skill_name" : "九子连环" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N身形围$n一转，使出「天罗地网」，$n的$l已完全笼罩在爪影下",
    "force" : 440,
    "dodge" : 30,
    "damage": 55,
    "lvl"   : 40,
    "skill_name" : "天罗地网" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N使一招「风卷残云」，双爪幻出满天爪影抓向$n全身",
    "force" : 520,
    "dodge" : 40,
    "damage": 70,
    "lvl"   : 60,
    "skill_name" : "风卷残云" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N吐气扬声，一招「唯我独尊」双爪奋力向$n天灵戳下",
    "force" : 620,
    "dodge" : 50,
    "damage": 100,
    "lvl"   : 100,
    "skill_name" : "唯我独尊" ,
    "damage_type" : "抓伤"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练九阴白骨爪必须空手。\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
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
    level   = (int) me->query_skill("jiuyin-baiguzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练九阴白骨爪。\n");
	me->receive_damage("qi", 30);
        me->add("neili", -20);
	return 1;
}
void skill_improved(object me)
{
    tell_object(me, HIR "你忽然从心底生出一股恶念：杀、杀、杀！我要杀绝天下人！\n" NOR );
    me->add("shen", -200);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n" NOR;
	}
}

