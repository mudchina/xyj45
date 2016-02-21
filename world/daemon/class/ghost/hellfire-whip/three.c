// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「神·人·鬼」？\n");

        if(!me->is_fighting())
                return notify_fail("「神·人·鬼」只能在战斗中使用！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("jinghun-zhang", 1) < 50)
                return notify_fail("你的惊魂掌级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("kusang-bang", 1) < 50)
                return notify_fail("你的苦丧棒级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");

        weapon=me->query_temp("weapon");
   me->delete("env/brief_message");
   message_vision("\n$N双手划一大圆，猛然托天而举，伴着天上雷鸣电闪，祭出了「神·人·鬼」三招。\n", me);

   me->set("HellZhen", 7);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->set("HellZhen", 6);
//   message_vision("\n$N双手一抖，手中$n顿时变的笔直，如同一根铁棍。\n", me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

   me->set("HellZhen", 1);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->delete("HellZhen");

   me->receive_damage("kee", 100);
   me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(3);
   return 1;
}
