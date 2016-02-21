// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//zhenhuo.c 【太乙真火】weiqi...980305

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int damage, ap, dp;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("你要对谁喷太乙真火？\n");

   if((int)me->query_skill("taiyi", 1) < 50 )
     return notify_fail("你的太乙仙法火候不够，哪里喷得出真火！\n");

   if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
     return notify_fail("你的法力不够，喷出的真火恐怕没有什么用！\n");

   if((int)me->query("force") < 100 )
     return notify_fail("你的内力不够，无法将真火喷出。\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("你现在神智不清，别把自己烧伤了！\n");

   me->add("mana", -25-(int)me->query("mana_factor"));
   me->add("force", -100);
   me->receive_damage("sen", 10);

   if( random(me->query("max_mana")) < 50 ) 
   {
     write("这一次好象不灵。\n");
     return 1;
   }

   msg = HIC "$N几个指头迅速捻动，突然张嘴一喷！红橙黄三道火焰呼！地一声向$n卷去！\n" NOR;

   ap = me->query_skill("spells");
   ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");
   if( random(ap + dp) > dp ) 
   {
     damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
     damage -= (int)target->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
     damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
     //here we can see if 2 players are at same status, the attacker has higher chance.
     if( damage > 0 ) 
     {
        //finally damage also depends on enabled spells level.
        damage +=random((damage*(int)me->query_skill("spells"))/100);
        msg += HIC "结果$n被烧得焦头烂额！\n" NOR;
        target->receive_damage("sen", damage, me);
        target->receive_wound("sen", damage/3, me);
        target->receive_damage("kee", damage, me);
        target->receive_wound("kee", damage/4, me);
        me->improve_skill("moonshentong", 1, 1);
     }
     else 
     {
        //here, cast failed and the target's mana_factor will be added to the previous 
        //damage to hurt yourself:(...note, damage<0.
        msg += HIC "结果火焰被$n以法力一逼，反向$N回卷而去！\n" NOR;
        damage -= (int)target->query("mana_factor");
        damage -= random((-damage*(int)target->query_skill("spells"))/100);
        me->receive_damage("sen", -damage, target);
        me->receive_wound("sen", -damage/3, target);
        me->receive_damage("kee", -damage, target);
        me->receive_wound("kee", -damage/4, target);
        me->improve_skill("taiyi", 1, 1);
     }
   } 
   else
     msg += "但是被$n躲开了。\n";

   message_vision(msg, me, target);
   if( damage > 0 ) COMBAT_D->report_status(target);
   else if( damage < 0 ) COMBAT_D->report_status(me);
   //damage=0 corresponding to "但是被$n躲开了。\n"--no report.   

   if( !target->is_fighting(me) ) 
   {
     if( living(target) ) 
     {
        if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(1+random(2));
   return 3+random(5);
}

