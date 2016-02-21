#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$N使出一招「三重天地混元」，左手聚出一团混元一气击向$n的$l",
                "force":                300,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「五重天地混元」，右手聚出一团混元一气击向$n的$l",
                "force":                500,
                "damage_type":  "瘀伤"
        ]),
	([ 	"action":
"$N使出一招「七重天地混元」，双手聚出一团混元一气击向$n的$l",
                "force":                700,
                "damage_type":  "瘀伤"
        ]),
	([	"action":
"$N使出一招「九重天地混元」，全身腾空而起，全身化作一团混元一气击向$n的$l",
                "force":                900,
                "damage_type":  "瘀伤"
        ]),
});
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
	int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(3*(me->query_skill("yiqiforce"))) > (damage_bonus + foo))
 {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->receive_wound("gin", (damage_bonus + foo));
                        victim->receive_wound("sen", (damage_bonus + foo));
			force = victim->query("force");
			victim->set("force", force-random(10)-1);
			victim->set("max_force", 0);
                        return
"$N的混元一气功摧毁了$n的真元！！！！\n";
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
return 	usage=="iron-cloth" ||
	usage=="unarmed" ||
	usage=="force";
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("混元一气功只能用学的。\n");
}

 
int effective_level() { return 50;}

string *absorb_msg = ({
        "$n身体虚转，双手微划，无坚不摧的混元一气功澎湃而出。\n",
        "$n施展出混元一气功，浑身肌肤坚如寒铁。\n",
        "$n身型微展，混元一气充斥了丈许空间。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",
});
string *parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int bounce_ratio()
{
	return 40;
}

int learn_bonus()
{
	return -5000;
}
int practice_bonus()
{
	return -5000;
}
int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("xianren") + "/yiqiforce/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/yiqiforce/" + action;
}
void skill_improved(object me)
{
        if( (int)me->query_skill("incarnation", 1)  < random(501) ) {
                tell_object(me,
                        HIR "\n你突然全身发麻！走火入魔了！！....\n\n" NOR);
		me->skill_death_penalty();
		me->delete_skill("yiqiforce");
		me->unconcious();
        } 
}

