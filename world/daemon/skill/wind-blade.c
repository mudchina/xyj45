// 
// 

inherit SKILL;
mapping *action = ({
	([	"action":		"$N手中的$w迎风一晃，刀锋带出裂锦般的声音，万马奔腾般地砍向$n的$l",
		"force":		400,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w迎风狂舞，象暴风中的滚沙，裹向$n的$l",
		"force":		300,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w象狂风中的流云，忽聚忽散地砍向$n的$l",
		"force":		100,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N晃动手中的$w，刀光忽隐忽现，象秋风中的落叶，一刀连一刀地散向$n的$l",
		"force":		100,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N聚起全身的功力，手中的$w象刺骨寒风般割向$n",
		"force":		200,
		"damage_type":	"割伤"
	]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 10 )
                return
                notify_fail("你的内功心法火候不足，无法练迎风一刀斩。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
int effective_level() { return 25;}

string *parry_msg = ({
	"$n慢慢地将手中的$v立于身前，强烈的刀风将$N逼得连退几步。\n",
});

string *unarmed_parry_msg = ({
        "$n手中的$v慢慢地挥出，剧烈颤动的刀锋封向$N。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("bandit") + "/wind-blade/" + action;
}

