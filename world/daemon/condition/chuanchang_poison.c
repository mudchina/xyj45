// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// chuanchang_poison.c

#include <ansi.h>

int update_condition(object me,int duration)
{
   int damage_kee = me->query("max_kee")/10; 
   int damage_sen = me->query("max_sen")/10;
   int myyf = me->query_skill("yaofa", 1)/10;
   int ff = me->query("force")/100;

   // 内力高, 发作轻
   if(ff < 1) ff = 1;
   damage_kee /= ff;
   damage_sen /= ff;

   // 妖法高, 发作轻
   if(myyf < 1) myyf = 1;
   damage_kee /= myyf;
   damage_sen /= myyf;

   if(damage_kee < 10) damage_kee = 10;
   if(damage_sen < 10) damage_sen = 10;

        me->receive_wound("sen", damage_sen);
        me->receive_wound("kee", damage_kee);
        me->set_temp("death_msg","穿肠毒发作死了。\n");
        me->apply_condition("chuanchang_poison", duration - 1);

   if ((int)me->query("kee") < (int)me->query("max_kee")/4)
     message_vision(HIR "$N肠如刀搅，浑身汗如雨下，看来病得不轻。\n" NOR, me);
   else if ((int)me->query("kee") < (int)me->query("max_kee")/2)
     message_vision(RED "$N双手捂住腹部，浑身发颤，好象肚子疼得厉害。\n" NOR, me);
   else
     message_vision("$N感到腹中一痛，不由得浑身一颤。\n", me);

   if( duration < 1 ) return 0;
        return 1;
}
