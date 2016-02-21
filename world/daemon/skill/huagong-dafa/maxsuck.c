// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// maxsuck.c

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	my_max = me->query("max_force");
	tg_max = target->query("max_force");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的丹元？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过丹元！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人丹元！\n");

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("你必须在战斗中才能吸取对方的丹元！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 90 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的丹元！n");

	if( (int)me->query("force",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("max_force") < 100 )
		return notify_fail( target->name() +
			"丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		return notify_fail( target->name() +
			"的内功修为远不如你，你无法从他体内吸取丹元！\n");

	message_vision(
		HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

	me->set_temp("sucked", 1);		

	if( random(sp) > random(dp) ) 
	{
		tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);

		target->add("max_force",  -1*(1+(me->query_skill("huagong-dafa", 1)-90)/10) );
		me->add("max_force",       1*(1+(me->query_skill("huagong-dafa", 1)-90)/10) );

		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
			me->add("potential",  10);
		me->add("combat_exp", 10);

		me->start_busy(random(10));
		target->start_busy(random(10));
		me->add("force", -20);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
		me->start_busy(10);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

