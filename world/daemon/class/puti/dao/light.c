// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展苍灵箭？\n");

        if((int)me->query("mana") < 100+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

   msg = HIC
"\n$N口中念了句咒文，半空走出一位容貌秀雅的电母，双手各持一枚铜镜。
铜镜相转，忽的闪出一道金光射向$n！\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 +
random((int)target->query("eff_sen") / 5);                   
     damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
     msg +=  HIR "\n结果「嗤」地一声，金光从$n身上透体而过，\n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
//finally damage also depends on enabled spells level.
     damage +=random((damage*(int)me->query_skill("spells"))/100);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/2, me);
                }
       else {
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note damage<0.
                        msg += HIC "\n结果金光被$n以法力反激，反而射中了$N！\n" NOR;
     damage -= (int)target->query("mana_factor");
     damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/3, target);
       }
             } 
   else
                msg += "\n但是被$n躲开了。\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "但是被$n躲开了。\n"--no report.   

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

