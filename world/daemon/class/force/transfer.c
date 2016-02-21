// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// transfer.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
   int force, trans;
   int tforce, tmaxforce;

   if( !target || target==me || !living(target) )
     return notify_fail("你要将真气传给谁？\n");

        if(target->is_busy())
           return notify_fail("对方正在忙着呢。\n");

        if(target->is_fighting())
           return notify_fail("对方正在忙着呢。\n");

   if( (string)me->query_skill_mapped("force") != target->query_skill_mapped("force") )
     return notify_fail(target->name() + "所使用的内功和你不同。\n");

   if( (int)me->query("force") <= (int)me->query("max_force") )
     return notify_fail("你的真气不足。\n");

   force = me->query("force") - me->query("max_force");

   if( force/2 < 1 ) return notify_fail("你的真气不足。\n");
   me->add("force", - force / 2 );
   message_vision("$N将手掌贴在$n背心，运气将体内真气传送过去。\n", me, target);
   if( random(force/3) > (int)me->query_skill("force") )
     return notify_fail("你失败了。\n");

   tforce = (int)target->query("force");
   tmaxforce = (int)target->query("max_force");
   write("Ok.\n");
   tell_object(target, HIY "你觉得一股热气从" + me->name() + "的手掌传了过来。\n" NOR);
   me->start_busy(2+random(4));
   target->start_busy(2+random(4));
        if( tforce < tmaxforce ) {
      tforce += force/6;
      if(tforce > tmaxforce) tforce = tmaxforce;
      target->set("force", tforce);
   }
   return 1;
}
