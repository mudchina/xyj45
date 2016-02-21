// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp, factor;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要引龙神袭击谁？\n");

        if((int)me->query("mana") < 200 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("你无法集中精力，别砸中自己了！\n");

   if((int)me->query_skill("seashentong") < 20 )
     return notify_fail("你的碧海神通修炼不精，龙神不会来的。\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 20);

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }
//cor 胆识
//cps 定力
   if( (int)me->query_cor() >= (int)me->query_cps() ) {

     msg = HIC"$N后退几步，口中念了几句咒文，大叫一声：“火德神龙何在？”\n\n"NOR;
     msg += HIC"半空中呼地现出两条气势威猛的金甲虬髯龙，纵身一吐，两股夹杂着无比腥气的烈焰冲着$n喷去！\n"NOR;
//divid by 10;

     factor = 5 + (int)me->query("bellicosity")/150 ;
     if (factor > 20){
        factor = 20;
     }
     if (factor < 10){
        factor = 10;
     }

           ap = me->query_skill("spells");
           ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
           ap += (int)me->query("combat_exp");
     ap = ap*factor/10;
           dp = target->query("combat_exp");

           if( random(ap + dp) > dp ) {
                   damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
                   damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);      
        damage += (int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                   if( damage > 0 ) {
          msg += HIC "结果$n躲避不及，被烧的遍体躏伤，浑身上下发出股焦气。\n" NOR;
//finally damage also depends on enabled spells level.
          damage +=random((damage*(int)me->query_skill("spells"))/80);
                           target->receive_damage("sen", damage*4/5, me);
                           target->receive_wound("sen", damage/3, me);
                           target->receive_damage("kee", damage*4/5, me);
                           target->receive_wound("kee", damage/4, me);
                           me->improve_skill("seashentong", 1, 1);
                   } else {
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note damage<0.
          msg += HIC "结果火势却被$n法力避住，反而是法主引火上身！\n" NOR;
          damage -= (int)target->query("mana_factor");
          damage -=random((-damage*(int)target->query_skill("spells"))/100);
                           me->receive_damage("sen", -damage*3/5, target);
                           me->receive_wound("sen", -damage/3, target);
                           me->receive_damage("kee", -damage*3/5, target);
                           me->receive_wound("kee", -damage/4, target);
            }
                } 
     else
                   msg += "但是被$n躲开了。\n";

           message_vision(msg, me, target);
           if( damage > 0 ) COMBAT_D->report_status(target);
           else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "但是被$n躲开了。\n"--no report.   

   }else{

                
           msg = HIC"$N后退几步，口中念了几句咒文，大叫一声：“水德神龙何在？”\n\n"NOR;
           msg += HIC"半空中呼地现出两条气势威猛的银角背苍龙，纵身一吐，两股奇寒无比的水柱冲着$n喷去！\n"NOR;
//divid by 10;

           factor = 5 + (int)me->query("force_factor")/15 ;
           if (factor > 20){
                   factor = 20;
           }
           if (factor < 10){
                   factor = 10;
           }
        
           ap = me->query_skill("spells");
           ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
           ap += (int)me->query("combat_exp");
           ap = ap*factor/10;
           dp = target->query("combat_exp");
                        
                        
           if( random(ap + dp) > dp ) {
                   damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
                   damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                   damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                   if( damage > 0 ) {
                     msg += HIC "结果$n躲避不及，被水柱激个正着！\n" NOR;
//finally damage also depends on enabled spells level.   
                     damage +=random((damage*(int)me->query_skill("spells"))/80);
                           target->receive_damage("sen", damage*4/5, me);
                           target->receive_wound("sen", damage/3, me);
                           target->receive_damage("kee", damage*4/5, me);
                           target->receive_wound("kee", damage/4, me);
                           me->improve_skill("seashentong", 1, 1);
                   } else {
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                     msg += HIC "结果水势却被$n法力避住，反而是冲向了法主！\n" NOR;
                     damage -= (int)target->query("mana_factor");
                     damage -=random((-damage*(int)target->query_skill("spells"))/100);
                           me->receive_damage("sen", -damage*3/5, target);
                           me->receive_wound("sen", -damage/3, target);
                           me->receive_damage("kee", -damage*3/5, target);
                 }
                }
           else
                   msg += "但是被$n躲开了。\n";

           message_vision(msg, me, target); 
           if( damage > 0 ) COMBAT_D->report_status(target);
           else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "但是被$n躲开了。\n"--no report.
        
   }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->fight_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

