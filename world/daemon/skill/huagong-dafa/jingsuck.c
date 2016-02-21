// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// jingsuck.c

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的精神？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过精神！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人精力！\n");

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("你必须在战斗中才能吸取对方的精神！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 45 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的精神。\n");

	if( (int)me->query("force",1) < 10 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("gin") < (int)target->query("max_gin") / 5 )
		return notify_fail( target->name() +
			"已经精神涣散，你已经无法从他体内吸取精力了！\n");

	message_vision(
		HIR "$N突然神秘的一笑，双掌一前一後对准$n的太阳穴拍了过来！\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

	me->set_temp("sucked", 1);		

	if( random(sp) > random(dp) )
	{
		tell_object(target, HIR "你猛觉额角两侧如针刺般剧痛，神志迷困，头脑中一片空白！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的精力自手掌源源不绝地流了进来。\n" NOR);

		target->receive_damage("gin", (int)me->query_skill("huagong-dafa", 1) );
		me->add("gin", (int)me->query_skill("huagong-dafa", 1) );

		if( target->query("combat_exp") >= me->query("combat_exp") ) {		
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);
		}

		me->start_busy(random(3));
		target->start_busy(random(3));
		me->add("force", -5);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->start_busy(3);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
