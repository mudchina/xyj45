// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("你只能将［太虚百幻］用在自己的身上。\n");
       if( (string)me->query("gender") != "女性" )
                return notify_fail("［太虚百幻］是只有女子才能练的功夫。\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("taixu") ) return 
	notify_fail("你已经在施展［太虚百幻］了。\n");
	skill = me->query_skill_eff_lvl("ghosty-steps");
	if(skill < 150) return notify_fail("你的太虚幻步太差了！\n");
	 me->add("force", -100);
        message_vision( HIR
"$N轻啸一声，使出太虚幻步中的［太虚百幻］，整个身行忽隐忽现，飘缈不定！\n" NOR, me);
        me->add_temp("apply/dodge", skill/5);
        me->set_temp("taixu", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/5 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("taixu");
        tell_object(me, "你的［太虚百幻］施展完毕，身行稳定了下来。\n");
}
 
