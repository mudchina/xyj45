#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
	object corp;
	if( !target ) target = offensive_target(me);

        if((int)me->query_skill("cursism") < 120 )
                return notify_fail("你的降头术不够高！\n");

	if( !target || target != me)
		return notify_fail("你只能对自己下这个降头．\n");
        if( (int)target->query_temp("boostcurse") ) return
	notify_fail("已经被下了降头。\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");
	me->receive_wound("kee", 100);
	msg = HIC "$N仰天长啸，将天地间的能量聚为一体．．．\n\n" NOR;
	message_vision(msg,me);
	target->add_temp("apply/agility", (int)target->query_agi()/5);
	target->set_temp("boostcurse",1);
	target->start_busy(1);
	me->start_busy(2);
	        target->start_call_out( (: call_other, __FILE__, "remove_effect", target,
(int)target->query_agi()/5 :), (int)me->query_skill("cursism")/7);

	return 1;
}
void remove_effect(object me, int amount)
{
        me->delete_temp("boostcurse");
        tell_object(me, "你身上的的降头失效了．\n");
	me->add_temp("apply/agility",-amount);
}

