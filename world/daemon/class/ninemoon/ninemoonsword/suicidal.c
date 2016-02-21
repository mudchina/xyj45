
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「唯我独尊」只能对战斗中的对手使用。\n");


	msg = RED "$N双目尽赤，祭出九阴赤炼剑最后一式「唯我独尊」，";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) {
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->receive_damage("kee",(int) me->query("max_kee"));
		target->receive_wound("kee",((int) me->query("max_kee")-20));
	} else {
		msg += "可是$p还是躲过了$P的最后一击！！\n" NOR;
	}
	message_vision(msg, me, target);
        me->unconcious();
	return 1;
}
