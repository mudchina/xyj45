// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("你只能将［漫天飞雪］用在自己的身上。\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("feixue") ) return 
	notify_fail("你已经在施展［漫天飞雪］了。\n");
	skill = me->query_skill_eff_lvl("notracesnow");
	if(skill < 150) return notify_fail("你的踏雪无痕太差了！\n");
	 me->add("force", -100);
        message_vision( HIR
"$N行功运气，身行居然缓缓上升，如风中的雪花！\n" NOR, me);
        me->add_temp("apply/dodge", skill/5);
        me->set_temp("feixue", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/5 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feixue");
        tell_object(me, "你的［漫天飞雪］施展完毕，身行稳定了下来。\n");
}
 
