#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        HIY "$n端坐微笑，忽而脸现庄严之色，$N立刻匍匐在地，虔诚膜拜。\n" NOR ,
});

mapping *action = ({
([      "action": HIR "$N拈花微笑，周身涌起一片祥云罩向$n" NOR ,
        "force" : 0,
        "dodge" : 0,
        "damage": 0,
        "lvl" : 0,
        "skill_name" : "君临天下",
        "damage_type":   "圣光之沐"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "unarmed" || usage == "parry" 
           || usage == "blade" || usage == "whip" || usage == "force" || usage == "claw" ;
}

string query_skill_name(int level)
{
        int i;
        return action[0]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        return action[0];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[0];
}

int valid_learn(object me)
{	
	if ( ! wizardp(me))
        return notify_fail("［君临天下］神功只能由巫师学习。\n");
}

string exert_function_file(string func)
{
    return __DIR__"king-of-dragon/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if ( ! userp (victim)) 
	if ( living (victim)) victim -> unconcious () ;
}

