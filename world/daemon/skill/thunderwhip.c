// snowwhip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([
		"action":		"$N惊叱一声，双手并举，寒光陡飞，霎时人鞭合一，凌空直向$n飞去",
		"dodge":		10,
		"damage":		30,
		"damage_type":	"刺伤"
	]),
	([
		"action":		"$N手中鞭影乍迸，卷起万重电光，“太古开天”轰然横扫。",
		"dodge":		50,
		"damage":		20,
		"damage_type":	"瘀伤"
	]),
	([
		"action":		"$N鞭式一变，杀机四布，展开了天雷破有去无回的杀招“太古伏羲说八卦”",
		"dodge":		40,
		"damage":		75,
		"damage_type":	"刺伤"
	]),
	([
		"action":	        "$N跃起三丈，身在半空，招式陡变，“太古神龙”如惊涛骇浪，卷转电擎而落",
		"dodge":		40,
		"damage":		30,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练天雷破, 多练些内力再来吧。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习天雷破。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍天雷破。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$n一鞭转空，身形籍式升空三尺，反手连戳三鞭“太古神龙三掉尾”，卷起一道鞭焰，护住全身。\n",
	"$n一招“横扣天机”，贯运真力，至截$N手中的$w\n",
	"$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
	"$n急踏步移形换位，让开这一招。\n",
	
});

string *unarmed_parry_msg = ({
        "$n一鞭转空，身形籍式升空三尺，反手连戳三鞭“太古神龙三掉尾”，卷起一道鞭焰，护住全身。\n",
        "$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
        "$n急踏步移形换位，让开这一招。\n",


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
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("yinshi") + "/thunderwhip/" + action;
}

