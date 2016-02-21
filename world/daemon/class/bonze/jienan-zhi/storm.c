// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 暴风骤雨
// dream 7/17/97
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「暴风骤雨」？\n");

        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

   if((int)me->query_skill("jienan-zhi", 1) <100)
     return notify_fail("你的劫难指级别还不够！\n");


        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

        if( random(me->query("max_force")) < 50 ) {
                write("糟糕，没成功！\n");
                return 1;
        }

   msg = HIC
"\n$N口中大喝了一声，施展出「暴风骤雨」，双手十指上下翻飞，身形前后左右移动，\n"
"$n只觉得到处是$N的影子，根本不知如何招架，更不用说躲闪了！\n\n" NOR;

        ap = me->query_skill("jienan-zhi", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) ) + (int)me->query("kee");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (4 * 400) ) + (int)target->query("kee");
   dp = dp*250 + target->query("combat_exp"); 
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_force") / 10 +
        random((int)me->query("eff_kee") /50);
                damage -= (int)target->query("max_force") / 10 +
        random((int)target->query("eff_kee") / 5);
     damage+=(int)me->query("force_factor")-random((int)target->query("force_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
     msg += HIC "结果十指结结实实全部击中了$n，差点没把$n戳了个透心凉！\n" NOR;
//finally damage also depends on enabled unarmed level.
     damage +=random((damage*(int)me->query_skill("unarmed"))/80);
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/4, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/3, me);
                        me->improve_skill("jienan-zhi", 1, 1);
                }
       else {
//here, cast failed and the target's force_factor will be added to the previous 
//damage to hurt yourself:(...note damage<0.
     msg += HIC "结果被$n以内力反激，$N反而自受其苦，双手受伤不轻！\n" NOR;
     damage -= (int)target->query("force_factor");
     damage -=random((-damage*(int)target->query_skill("unarmed"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/4, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/3, target);
                        me->improve_skill("jienan-zhi", 1, 1);
       }
             } 
   else
                msg += "但是被$n躲开了。\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "但是被$n躲开了。\n"--no report.   

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}

