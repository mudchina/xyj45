// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"one",
		"action":		"$NÉÏÇ°Ò»²½£¬ÊÖÖÐ$w¶¾Éß°ã´ÌÏò$nµÄ$l",
		"dodge":		50,
		"damage":		70,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"two",
		"action":		"$NÉíÐÎÒ»×ª£¬·´ÊÖÒ»»Ó£¬ÊÖÖÐ$w´ÌÏò$nµÄ$l",
		"dodge":		50,
		"damage":		20,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"three",
		"action":		"$nÑÛÇ°Ò»»¨£¬$NÊÖÖÐµÄ$wÒÑ¾­Ñ¸½ÝÎÞ±ÈµÄ´ÌÏò$nµÄ$l",
		"dodge":		40,
		"force" :		100,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"four",
		"action":		"$NÖ»¹¥²»ÊØ£¬ÊÖÖÐ$wÒ»¶¶£¬Íù$nµÄ$l´Ì³öÒ»½£",
		"dodge":		40,
		"damage":		40,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"five",
		"action":		"$NµÄ¡¸×óÊÖ½£·¨¡¹Ö»ÓÐ[31m´Ì[37m£¬¼òµ¥¶øÓÐÐ§µØÍù$nµÄ$l´ÌÈ¥",
		"dodge":		60,
		"damage":		80,
		"force" :		100,
		"damage_type":	"´ÌÉË"
	]),
	([	"name":			"six",
		"action":		"$NÊÖÖÐ$wÖ±Ö¸$n$l£¬·¢³ö±ÆÈË½£ÆøÉÁµç°ã´ÌÈ¥",
		"dodge":		20,
		"damage":		20,
		"damage_type":	"´ÌÉË"
	]),
});

int valid_learn(object me)
{
	object ob;


	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØÐëÏÈÕÒÒ»°Ñ½£²ÅÄÜÁ·½£·¨¡£\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓÐ°ì·¨Á·Ï°×óÊÖ½£¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("Äã°´ÖøËùÑ§Á·ÁËÒ»±é×óÊÖ½£·¨¡£\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\nÄãÍ»È»¾õµÃÒ»¹É¶ñÆø³åÉÏÐÄÍ·£¬Ö»¾õµÃÏëÉ±ÈË....\n\n" NOR);
		me->add("bellicosity", 10);
	} else
		me->add("bellicosity", 1);
}
int effective_level() { return 10;}

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
	return -20;
}
string perform_action_file(string action)
{
        return CLASS_D("assassin") + "/lefthand-sword/" + action;
}

