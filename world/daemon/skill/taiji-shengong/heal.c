// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功修为还不够。\n");
	if( (int)me->query("force") < 50 ) // - (int)me->query("max_force") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
	message("vision",
		HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
		environment(me), me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("jiali", 0);

	return 1;
}
