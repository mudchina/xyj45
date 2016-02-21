// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt;
	object weapon;
	extra = me->query_skill_eff_lvl("sharen-sword",1);
	if ( extra < 90) return notify_fail("你的杀人剑法法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［杀人如麻］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	msg = HIY  "$N凶性大发，手中的"+ weapon->name()+  "狂风暴雨般地向$n卷来！" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/10);
	me->add_temp("apply/damage",extra/10);
	lmt = random(5)+3;
	for(i=1;i<=lmt;i++)
	{
	msg =  HIR "第"+chinese_number(i)+"剑！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
	me->start_busy(5);
	return 1;
}
