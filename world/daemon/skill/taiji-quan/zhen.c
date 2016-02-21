// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhen.c 太极拳「震」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("神功震敌只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「震」字诀！\n");		
		
        if( (int)me->query_skill("taiji-quan", 1) < 30 )
		return notify_fail("你的太极拳不够娴熟，不会使用「震」字诀。\n");
	                        
        if( (int)me->query_skill("taiji-shengong", 1) < 30 )
		return notify_fail("你的太极神功不够高，不能用来反震伤敌。\n");
			
        if( (int)me->query("force", 1) < 100 )
		return notify_fail("你现在内力太弱，不能使用「震」字诀。\n");
			
	msg = CYN "$N默运神功，使出太极拳「震」字诀，企图以内力震伤$n。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("taiji-shengong", 1);
		
		damage = damage/2 + random(damage);
		
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/3);
		me->add("force", -damage/10);
		
		if( damage < 20 ) msg += HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
        	else if( damage < 40 ) msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
        	else if( damage < 80 ) msg += RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
        	else msg += HIR"结果$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
		
	} else 
	{
		me->start_busy(1);
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
