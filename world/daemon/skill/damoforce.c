// 
// 

#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return 
notify_fail("达摩易筋经只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("bonze") + "/damoforce/" + func;
}
int effective_level() { return 30;}
int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}
void skill_improved(object me)
{
        int s;

        s = me->query_skill("damoforce", 1);
        if(!(s%10) && (int)me->query("con") < s/4){ 
                tell_object(me, HIG
"你学着学着达摩易筋经，突然感到丹田之气喷涌而出！！\n" NOR);
                me->add("con", 1);
		me->unconcious();
        }
}
