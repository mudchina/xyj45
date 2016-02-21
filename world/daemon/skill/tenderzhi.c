// tenderzhi.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N左手一挥，一招「菊楼采月」右手点向$n$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
        ([      "action":               
"$N使一招「雪桥翦梅」，身影忽前忽後，突然一转身左手往$n的$l点去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "左手中指",
        ]),
        ([      "action":               
"$N身法稍顿，左手一扬使出「柳亭簪花」往$n的$l点去",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "左手中指",
        ]),
        ([      "action":               
"只见$N纤腰一摆，陡然滑出数尺，右手顺著来势一招「桃坟扑蝶」往$n的$l点去",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "女性" )
                return notify_fail("柔虹指是只有女子才能练的武功。\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练柔虹指必须空手。\n");
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
        "$n中指微弹$N$w的尖端，$N手中的$w几乎脱手而出。\n",
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

