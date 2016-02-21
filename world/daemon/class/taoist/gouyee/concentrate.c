// concentrate.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        int mana_gain;

        if( target && target!=me )
                return notify_fail("「灵神诀」只能用来恢复自己的法力。\n");

        if(amount == -1) amount = 30;
        else if(amount < 30 ) 
                return notify_fail("最少用三十内力。\n");

        if( (int)me->query("force") < amount )
                return notify_fail("你的内力不够。\n");

        
        mana_gain =  (10 + (int)me->query_skill("force")/5)*amount/30;
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana") )
                me->set("mana", (int)me->query("max_mana"));
        else
                me->add("mana", mana_gain);
        me->add("force", -amount);
        me->receive_damage("sen", 10);

        message_vision(
                HIY "$N闭目凝神，用谷衣心法的内力运转了一次「灵神诀」...\n"
                "一股青气从$N身上散出，汇聚在$P的顶心，然後缓缓淡去。\n" NOR, 
me);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}
 
