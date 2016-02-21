// tenderzhi.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N双手一挥，一招「翔龙在天」右手划向$n$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               
"$N身影缥渺，使一招「云龙突现」，转身左手往$n的$l拍去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               
"$N身形忽然平地拔起，双手散出满天掌影，一招「神龙摆尾」往$n的$l挥去",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               
"只见$N双手一摆，顺著来势一招「画龙点睛」往$n的$l点去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练飞龙探云手必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("sen", 30);
        me->add("force", -10);

        return 1;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$n双手急抓$N的手腕，$N手中的$w几乎脱手而出。\n",
});

string *unarmed_parry_msg = ({
        "$n并起二指，凌空虚点，指风直奔$N的周身大穴。\n",
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
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("yinshi") + "/flying-dragon/" + action;
}

