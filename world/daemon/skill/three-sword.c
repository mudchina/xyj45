// three-sword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出天字诀中的「日月互转」，$w交于左手，向$n的$l刺来",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N左手握成天字诀，右手中的$w使出一招「风云突起」，斩向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出一招地字诀中的「山水相连」，身形婉如流水，手中$w有如泰山地斩向$n的$l",
                "dodge":                40,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一式地字诀中的「水火无情」对准$n的$l刺出一剑",
                "dodge":                40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w一招人字诀中的「众生平等」，化出无数剑尖向$n刺出",
                "dodge":                40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N双手握剑，一招人字诀中的「生老病死」刺向$n的$l",
                "dodge":                420,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练三才剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return  notify_fail("你的内力或气不够，没有办法练习三才剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍三才剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("wudang") + "/three-sword/" + action;
}
 
int effective_level() { return 17;}

string *parry_msg = ({
        "$n使出「天」字诀，以攻为守、身随剑动，将$N迫得连连后退。\n",
        "$n使出一招地字决中的「地动天摇」，手中的$v含着内力震开了$N的$w。\n",
        "$n不顾$N的$w，一招人字决中的「人非人、我非我」，向$N的头上砍去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v化做三道剑气，迫得$N连连后退。\n",
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
	return -20;
}
int practice_bonus()
{
	return -30;
}
int black_white_ness()
{
	return 30;
}

