// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("unarmed");
	if ( extra < 150) return notify_fail("你的少林长拳还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［玉环鸳鸯拳］只能对战斗中的对手使用。\n");
	me->add("force_factor",extra/5);
	me->set("force",extra/5*10);
	me->add_temp("apply/attack",extra/10);
	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出少林长拳中的［玉环鸳鸯拳］，一招连环七式向$n攻出！\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "上一拳！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "下一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "左一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "右一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "前一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "后一拳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "最后再一拳！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(5);
	me->set("force_factor",0);
        me->set("force",0);
        me->add_temp("apply/attack",-extra/10);
	return 1;
}
