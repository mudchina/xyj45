// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//天女散花 
// dream 7/17/97
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
   int number, size, i, four;
   object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天女散花」？\n");

        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

   if((int)me->query_skill("baihua-zhang", 1) <80)
     return notify_fail("你的百花掌级别还不够！\n");

   tar=all_inventory(me);
        size = sizeof(tar); 
   if(size) {
           for(i=0;i<size;i++)
      if(tar[i]->query("material") == "flower") {
        number++;
     }
     }

   
   if((int)number < 5)
     return notify_fail("你的花不足以施展「天女散花」！\n");

        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

   msg = HIC
"\n$N微微一笑，身子凌空而起，洒下漫天花雨，一时花香缭绕\n"
"$n只觉周身都被花影罩住了，一时竟然不知如何招架，更不用说躲闪了！\n" NOR;

        ap = me->query_skill("baihua-zhang", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) );
// + (int)me->query("kee");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (4 * 400) );
// + (int)target->query("kee");
   dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
     msg += HIC "谁知$n竟险中求胜，长袖一摆，已将所有花瓣打落！\n\n"NOR;
           message_vision(msg, me, target);
   } else {
                damage = (int)me->query_skill("baihua-zhang",1) / 10 +
        (int)me->query("sen") / 400 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 400 + random((int)me->query("kee") / 200 );
     msg += HIC "这些花瓣看似柔弱无力，却如疾风骤雨般射向$n,深深的嵌入肉里！\n" NOR;
     if (number < 10) damage +=random(number+1);
     else damage +=random(10);
                        target->receive_damage("sen", me->query("eff_sen")*damage/100, me);
                        target->receive_damage("kee", me->query("eff_kee")*damage/70, me);
                        me->improve_skill("baihua-zhang", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
    }


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
   for (i = 0; i< size; i++){
     if (tar[i]->query("material") == "flower"){
     four++;
     if (four <= 5)
     destruct(tar[i]);
     else
     break;
     }
   }
        me->start_busy(3);
        return 1;
}

