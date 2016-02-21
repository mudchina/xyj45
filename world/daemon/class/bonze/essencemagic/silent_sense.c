// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	int lvl;
	if( target ) return notify_fail("寂识神通只能对自己使用。\n");
	if( me->query("atman") < 1000 )
		return notify_fail("你的灵力不够！\n");
	lvl = (int) me->query_skill("essencemagic",1);
        if( me->query("gin") <= 50 )
                return notify_fail("你的精不够！\n");
	me->add("atman", -50);
	me->receive_damage("gin", 50);
	message_vision(HIY "$N盘膝而座，开始运用寂识神通静思入定 ...\n" NOR, me);
	if( random(me->query_skill("magic")) > (int)me->query_int() * 10 ) {
		if( random(me->query("max_atman")) < (int)me->query("atman")/2 ) {
			me->set_skill("essencemagic", lvl -1 );
			write( HIR "你觉得脑中一片混乱，你的八识神通降低了！\n" NOR );
			return 1;
		}
			me->set_skill("essencemagic", lvl + 1);
			write( HIG "你的八识神通提高了！\n" NOR );
			return 1;
	}
	write("可是你只觉得一无所获。\n");
	return 1;
}
