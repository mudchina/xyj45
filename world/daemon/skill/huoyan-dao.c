//
// huoyan-dao.c 火焰刀
// Designed by secret(秘密)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「钻木取火」，飞身急转，双掌向前平平拍向$n",
        "skill_name" : "钻木取火",
        "force" : 100,
        "lvl" : 0,
        "damage" : 60,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「祝融怀焰」，手掌如刀，斜斜劈向$的$l",
        "skill_name" : "祝融怀焰",
        "force" : 150,
        "lvl" : 10,
        "damage" : 80,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「风火无边」，双掌一拍，一道内力自掌中攻向$n的$l",
        "skill_name" : "风火无边",
        "force" : 200,
        "lvl" : 20,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「六道轮回」，双手合十，当头劈向$n",
        "skill_name" : "六道轮回",
        "force" : 250,
        "lvl" : 30,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「双龙吐焰」，双掌一错，两道内力交叉攻向$n的$l",
        "skill_name" : "双龙吐焰",
        "force" : 300,
        "lvl" : 40,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「刀山火海」，双掌向下斜拍，顿时万千道内力从四面八方攻向$n",
        "skill_name" : "刀山火海",
        "force" : 350,
        "lvl" : 60,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「白佛光度」，左臂回收，右掌引内力直刺$n的$l",
        "skill_name" : "白佛光度",
        "force" : 400,
        "lvl" : 80,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「火内莲花」，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n",
        "skill_name" : "火内莲花",
        "force" : 500,
        "lvl" : 100,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
});


int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练火焰刀必须空手。\n");

	else if ((int)me->query("max_neili") < 300)	//  火焰刀要有很高的内力才能学
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("longxiang", 1) >= 60 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 60)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 60)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 60)
		return notify_fail("你的小无相功火候太浅。\n");
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
		  level   = (int) me->query_skill("huoyan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练火焰刀必须空手。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够，练不了火焰刀。\n");
	me->receive_damage("qi", 20);
	return 1;
}


string perform_action_file(string action)
{
	return __DIR__"huoyan-dao/" + action;
}

