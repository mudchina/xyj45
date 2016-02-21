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

	if( !target
	|| !target->is_ghost()
	||	target==me)
		return notify_fail("你只能对鬼魂下这个降头。\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");
	if(!corp = present("corpse",environment(me)))
		return notify_fail("你的周围没有尸体！\n");
	me->receive_wound("kee", 100);
	msg = HIC "$N凌空对着$n虚点几下，$n缓缓的站了起来！\n\n" NOR;
	message_vision(msg,me,corp);
	destruct(corp);
	target->be_ghost(0);
	target->set("title",HIB"借尸还魂"NOR);
	me->start_busy(2);
	return 1;
}

