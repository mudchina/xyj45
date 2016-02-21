// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N单脚金鸡独立，缓缓展出龙凤双环的起手式「八面威风」，手中$w挥向$n的丹田！",
                "force":               50,
                "dodge":                40,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w相碰，发出＂隆隆＂声，一招「先声夺人」攻向$n$l！",
                "force":               60,
                "dodge":                20,
                "parry":                -60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w凌空一挥，使出龙凤双环中的「龙飞凤舞」击向$n$l！",
                "force":               50,
                "dodge":                10,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「游龙在天」，$w夹杂着风声撞向$n$l！",
                "force":               80,
                "dodge":                10,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("你必须先找一双环或者是类似的武器，才能练龙凤双环。\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("你的体力不够练龙凤双环，还是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 20;}
 
string *parry_msg = ({
        "结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
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
	return -100;
}
int black_white_ness()
{
	return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("assassin") + "/longfenghuan/" + action;
}

