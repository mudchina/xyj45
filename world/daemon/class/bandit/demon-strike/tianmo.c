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
		return notify_fail("［天魔式］只能对战斗中的对手使用。\n");
	extra = me->query_skill("demon-strike",1) ;
	if(extra < 80 ) return notify_fail("你的［如意地魔连环八掌］不够熟练！\n");
	msg = HIR "\n$N双臂暴长，一招［天魔式］，双手拢向$n！" NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIC "$N躲闪不及，全身正被掌影罩住！ 一股青气从$N顶门喷涌而出！\n" NOR,target);
	target->receive_wound("gin",extra);
	me->receive_heal("gin",extra);
	}	
	else{
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	me->start_busy(2);
	return 1;
}
