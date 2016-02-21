// void_sense.c

#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
	int lvl,i;
	object env, *inv;
	lvl = (int) me->query_skill("magic");
	lvl += (int) me->query("spi");
        if ( lvl <= 80)
                return notify_fail("你法术不够高！\n");
	if( me->query("atman") < 30 )
		return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 15 )
                return notify_fail("你的精不够！\n");
	me->add("atman", -30);
	me->receive_damage("gin", 15);
	message_vision(HIW "$N微一凝神，闭著眼睛使出八识神通中的灵识．．．\n" NOR, me);
	        me->add_temp("apply/astral_vision", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), lvl);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;

}
void remove_effect(object me)
{
        me->add_temp("apply/astral_vision", -1);
        tell_object(me, "你的灵识失效了。\n");
}

