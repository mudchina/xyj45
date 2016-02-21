// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// dagou-bang.c

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
	"dodge": -10,
	"damage": 30,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
	"dodge": -20,
	"damage": 40,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",
	"dodge": -30,
	"damage": 50,
	"damage_type": "挫伤"
]),
([	"action": "$N施出「拨狗朝天」，$w由下往上向$n撩去",
	"dodge": -20,
	"damage": 40,
	"damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        if (!me) me = this_object();
	if (random(me->query_skill("staff")) > 60 &&
	    me->query_skill("force") > 60 &&
	    me->query("force") > 100 &&
	    (string)weapon->query("id") == "yuzhu zhang" ) {
		me->add("force", -100);
		return ([
		"action": "$N眼中射出一道青芒，手中玉竹杖使出「天下无狗」，劈天盖地般攻向$n",
		"damage": 500,
		"damage_type": "挫伤"]);
	}
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练打狗棒法。\n");
	me->receive_damage("kee", 40);
	return 1;
}

