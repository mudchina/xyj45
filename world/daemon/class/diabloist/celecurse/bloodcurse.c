#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;

	if( !target ) target = offensive_target(me);

        if((int)me->query_skill("cursism") < 30 )
                return notify_fail("你的降头术不够高！\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个降头？\n");

	if((int)me->query("kee") < 25 )
		return notify_fail("你的气血不够！\n");

	me->receive_wound("kee", 25);
	msg = HIC "$N的眼中红光一闪，一条细如发丝的血线射向$n！\n\n" NOR;

	ap = me->query_skill("cursism");
	extradam = ap/2;
	ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
		damage = me->query("bellicosity") /50 ;
			msg +=  HIR "血线无声无息地渗入$p的体内．．．\n" NOR;
       		         message_vision(msg, me, target);
			target->receive_damage("kee", damage, me);
			target->receive_wound("kee", damage/3, me);
		        if( damage > 0 ) COMBAT_D->report_status(target);

	} else
		{
		msg += "但是被$n发现了！！\n";
	        message_vision(msg, me, target);
		target->kill_ob(me);
		me->kill_ob(target);
		}
	me->start_busy(2);
	return 1;
}

