// 
// 

inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N左腿在前，右腿在后，双掌用力向$n的$l挥来",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左脚点地，身体向后旋转，右腿向疾风扫落叶般扫向$n的$l",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右手虚晃，左肘从我意想不到的角度撞向我$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踢出三脚",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N凌空跃起，身体向后急转，双脚从下往上一前一后地撩向$n的$l",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练空手道必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
});

string *unarmed_parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
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
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
        return CLASS_D("bandit") + "/kongshoudao/" + action;
}

