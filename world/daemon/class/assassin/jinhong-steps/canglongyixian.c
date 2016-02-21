// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［苍龙乍现］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("jinhong-steps",1) / 10;
	me->add_temp("apply/attack", extra);	
	msg = HIR  "$N脚下一转，突然身形飞起，双脚如矫龙般腾空一卷，猛地向$n踢出！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
	me->start_busy(2);
	return 1;
}
