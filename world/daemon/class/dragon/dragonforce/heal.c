// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中疗伤？找死吗？\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
   message_vision("$N盘腿而坐，全身发出股青气，伤口也渐渐愈合了。\n", me);

        me->receive_curing("kee", 20 + (int)me->query_skill("force")/5 );
        me->add("force", -40);

        return 1;
}

