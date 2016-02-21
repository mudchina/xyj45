// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("deisword",1);
	if ( extra < 50) return notify_fail("你的蝶恋花剑法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［彩蝶狂舞］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出蝶恋花剑法中的［彩蝶狂舞］，一招连环三剑，手中的"+ weapon->name()+  "闪电般向$n攻出第一剑！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第二剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第三剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->start_busy(5);
	return 1;
}
