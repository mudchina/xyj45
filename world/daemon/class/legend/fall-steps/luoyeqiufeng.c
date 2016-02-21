// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("fall-steps",1);
	if ( extra < 90) return notify_fail("你的［秋风步］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［落叶秋风］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision("$N脚踏八方，身行如秋风中的落叶，飘渺不定！\n",me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision("结果$N被扰得眼花潦乱，接应不暇！\n",target);
	target->start_busy(3);
	}
	else{
	msg = "可惜$N看出了$n的身法，向你迅然攻击！";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
