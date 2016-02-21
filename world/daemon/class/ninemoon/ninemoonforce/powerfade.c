// powerfade.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
notify_fail("你只能用九阴心经压制自己的杀气。\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("你的内力不够。\n");
        if( me->query_temp("powerup") ) return 
notify_fail("你已经在运功中了。\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("你现在毫无杀气。\n");

        skill = me->query_skill("force");

        me->add("bellicosity", - 50 - skill/4 );
        me->add("force", -100);
        me->receive_damage("sen", 100);

        message_vision(
                HIC "$N双眼微合，施展九阴心经，放慢呼吸，开始收敛自己的阴气 
....\n" NOR, me);

        if( me->is_fighting()
        &&      (random(skill) < (int)me->query("cps") * 3 ) )
                me->unconcious();

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/damage", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的九阴心法运行完毕，将内力收回丹田。\n");
}
 
