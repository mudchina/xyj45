// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("你只能将［八仙醉酒］用在自己的身上。\n");
	if(!me->query_condition("drunk"))
	return notify_fail("你现在好象一点醉意也没有耶！\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("zuixian") ) return 
	notify_fail("你已经在施展［八仙醉酒］了。\n");
	skill = me->query_skill_eff_lvl("zuixian-steps");
	if(skill < 100) return notify_fail("你的醉仙望月步太差了！\n");
	 me->add("force", -100);
        message_vision( HIR
"$N左摇右摆，俨然是醉仙望月步中的［八仙醉酒］，整个身形摇摆不定！\n" NOR, me);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("zuixian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/3 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("zuixian");
        tell_object(me, "你的［八仙醉酒］施展完毕，身行稳定了下来。\n");
}
 
