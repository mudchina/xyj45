// 
// 

inherit SKILL;
mapping *action = ({
	([	"action":		"$N使出天魔八式中的起手式“万魔初醒”，手中的$w划出一溜光芒斩向$n的$l",
		"force":		500,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手一抖，一招“魔焰万丈”手中的$w幻成一片刀花，散向$n的$l",
		"force":		300,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N刀锋忽转，手中的$w一招“魔光乍现”，闪电般劈向$n的$l",
		"force":		200,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N身影晃动，刀锋忽左忽右，一招“天魔独尊”，手中的$w，从中路突然砍至$n的$l",
		"force":		300,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N的双脚点地，刀背贴身，一招“万刃天魔”全身转出一团刀光滚向$n",
		"force":		200,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N刀刃向上，一招“天魔回天”，从一个$n意想不到的角度撩向$n的$l",
		"force":		200,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N你手中的$w左右横划，一招“天魔七现”，来来回回地狂扫向$n的$l",
		"force":		100,
		"damage_type":	"割伤"
	]),
        ([      "action":               "$N使出如意天魔连环八式中的收手式“万魔归宗”，手中的$w迅捷无比地砍向$n的$l",
                "force":                500,
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 10 )
                return
                notify_fail("你的内功心法火候不足，无法练如意天魔连环八式。\n");
        if( (int)me->query_skill("demon-force", 1) < 60 )
                return
		notify_fail("你的天地人魔心法火候不足，无法练如意天魔连环八式。\n");
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
int effective_level() { return 20;}

string *parry_msg = ({
	"$n使出天魔连环八式中的“魔障无边”，手中的$v化成九重刀幕护住全身。\n",
});

string *unarmed_parry_msg = ({
        "$n使出天魔连环八式中的“魔障无边”，手中的$v化成九重刀幕护住全身。\n",
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
	return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("bandit") + "/demon-blade/" + action;
}

