// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("你只能用龙神心法保护自己。\n");

        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("dragonforce",1);

        me->add("force", -100);
        me->receive_damage("kee", 20);

        message_vision(
                HIR
"$N微一凝神，运起龙神心法，浑身上下顿时结出了青色的龙鳞，身形变的异常高大，站在那里看起来威风凛凛。\n" NOR, me);

        me->add_temp("apply/armor", skill/3);
   me->add_temp("apply/damage",skill/6);
   me->add_temp("apply/unarmed", skill/6);
//   me->add_temp("apply/strength",skill/6);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
   me->add_temp("apply/damage", -amount/2);
        me->add_temp("apply/unarmed", -amount/2);
//      me->add_temp("apply/strength", -amount/2);
        me->delete_temp("powerup");
        tell_object(me, "你的龙神心法运行一周天完毕，龙鳞渐渐消去了。\n");
}

