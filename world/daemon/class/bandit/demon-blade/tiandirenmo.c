// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	object weapon;
	extra = me->query_skill("demon-blade",1);
	if ( extra < 90) return notify_fail("你的［天地人魔连环八式］还不够纯熟！\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "demon-steps")
			return notify_fail("［天地人魔］需要如意人魔连环八步的配和！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天地人魔］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	msg = HIY  "$N神气贯通，将天地人魔连环八式一气呵成！\n万魔初醒！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "魔焰万丈！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "魔光乍现！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔独尊！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万刃天魔！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔回天！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔七现！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万魔归宗！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(9);
	return 1;
}
