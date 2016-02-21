// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	int lvl;
	if( !target ) target = me;
	lvl = (int) me->query_skill("essencemagic",1);
	lvl = lvl + (int) me->query("spi");
	if( (int)me->query("atman") < 50 ) return notify_fail("你的灵力不够！\n");
	me->add("atman", -50);
	if( random(lvl) <= 45) {
        write("你因为对八识神通的修行不够高深而失败了。\n");
                return 1;
	}
	target->receive_curing("sen", 50);
	if(me != target)
	message_vision( HIY "$N闭目凝神，印堂发出一道金芒罩住$n的全身...\n" NOR, me, target);
	else
	message_vision( HIY "$N闭目凝神，印堂发出一道金芒罩住$N的全身...\n" NOR, me);
	return 1;
}
