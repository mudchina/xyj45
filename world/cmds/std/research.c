
#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	int gin_cost;	
	int my_skill;
	int pot;
	int amount;
        if( me->is_fighting() )
                return notify_fail("在战斗中搞研究？\n");
	if(!arg) return notify_fail("指令格式: research <技能>\n");
	if( !(int)my_skill=me->query_skill(arg,1) )
                return notify_fail("你对此项技能一无所知，如何搞研究？\n");
                                                                                
        if( !SKILL_D(arg)->valid_learn(me) ) return 0;
//	if( !SKILL_D(arg)->valid_research(me) ) return 0;

	pot = (int)me->query("potential") - (int) me->query("learned_points");
        gin_cost = 10000 * 3 / ((int)me->query_int()*(int)me->query_kar());
	if((int)me->query("gin") < gin_cost)
	{
	me->set("gin",0);
	return notify_fail("你现在太累了，结果什么也没有研究出来。\n");
	}
	amount = (my_skill - 75) * SKILL_D(arg)->black_white_ness()/100;
	amount += SKILL_D(arg)->learn_bonus() +
		  (int)me->query_int() * (int)me->query_int() +
		  to_int(pow(to_float((int)me->query("combat_exp")),0.3));
	amount = pot/10*(amount/100 + random(amount/100));
	me->add("learned_points",pot);
        me->receive_damage("gin", gin_cost );
	me->research_skill(arg,amount);
	write("你对"+to_chinese(arg)+"作了一番彻底的研究！\n");
        return 1;
}
int help(object me)
{
   write( @HELP
指令格式: research <技能>

这一指令让你用所有的潜能对某项技能作深入的研究。
HELP
   );
   return 1;
}

