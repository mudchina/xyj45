
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{ 
       if( (string)me->query("gender") != "女性" )
                return notify_fail("九阴心经是只有女子才能练的内功。\n");




return 1; 
}

int practice_skill(object me)
{
        return 
notify_fail("九阴心经只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("ninemoon") + "/ninemoonforce/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(3*(me->query_skill("nine-moon-force"))) > (damage_bonus + 
foo) ) {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->apply_condition("ninemoonpoison", factor/2);
                        return 
"$N的招式挟著一股阴寒无比的劲风使得$n不禁打了个寒噤。\n";
                }
        }
        return foo;
}
 
int effective_level() { return 10;}

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

