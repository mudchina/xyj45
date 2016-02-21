// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出一招「乱泼狂风」，右掌从肋下穿出击向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「狂风突袭」，左掌化虚为实击向$n的$l",
                "dodge":                10,
                "parry":                30,
                "force":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出泼风掌法「风动天庭」，拔地而至$n身前，一掌拍向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「风雨交加」，对准$n的$l拍出一排掌影",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「狂风扫叶」击向$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练泼风掌必须空手。\n");
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
        "$n化掌为刀，一招「晓风残月」急切$N拿着$w的手。\n",
        "$n略一转身，一招「风动树梢」拍向$N拿着$w的手。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n化掌为指，一招「恶风怒啸」反点$N的周身要穴。\n",
        "$n施展出「狂风怒吼」，轻描淡写的化解了$N的攻势。\n",
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
        return CLASS_D("lishi") + "/pofeng-strike/" + action;
}


