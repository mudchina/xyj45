// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// bandaged.c

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( (int)me->query("eff_gin") < (int)me->query("max_gin") )
                me->receive_curing("gin", 3);

        me->apply_condition("jing_curing", duration - 1);
        if( !duration ) return 0;

        return CND_CONTINUE;
}
