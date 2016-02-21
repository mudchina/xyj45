// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//
inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");

   if((string)me->query("family/family_name")!="阎罗地府" )
     return notify_fail("你试着将自己化为气体，可血肉之躯却怎么也化不开！\n");

        message_vision("$N喃喃地念了几句咒语。\n", me);

   if(me->is_fighting() ) {
     if(random((int)me->query("max_mana")) >
(int)target->query("max_mana")/2) {

message_vision("$N口中喷出一股黑风，整个人也随着黑风散去．．．\n", me);
me->receive_damage("sen", 100);
me->move("/d/death/gate");
   }
   else
message_vision("$N转身想跑，却被$n一个箭步拦住．\n", me, target);
me->receive_damage("sen", 100);
   }
   if(!me->is_fighting() ){

message_vision("$N口中喷出一股黑风，整个人也随着黑风散去．．．\n", me);
   me->receive_damage("sen", 100);
   me->move("/d/death/gate");
   }
//        me->start_busy(1+random(2));
        return 5+random(5);
}

