// tie@fengyun

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");

	extra = me->query_skill("feixian-sword",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIW  "$N内带天外飞仙剑法中的精髓，闪电般的击向$n，\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
