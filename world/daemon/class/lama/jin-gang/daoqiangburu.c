// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("你只能将［刀枪不入］用在自己的身上。\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("daoqian") ) return 
	notify_fail("你已经在施展［刀枪不入］了。\n");
	skill = me->query_skill_eff_lvl("jin-gang");
	if(skill < 100) return notify_fail("你的金刚不坏功太差了！\n");
	skill = random(skill/2)+skill/2;
	me->add("force", -100);
        message_vision( HIR
"$N拍了拍胸脯，高叫着：＂刀枪不入！刀枪不入！刀枪不入！．．．＂\n" NOR, me);
        me->add_temp("apply/iron-cloth", skill);
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/5);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("daoqian");
        tell_object(me, "你的［刀枪不入］的功效散光了。\n");
}
 
