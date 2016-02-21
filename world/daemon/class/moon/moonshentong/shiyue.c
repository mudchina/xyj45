// …Òª∞ ¿ΩÁ°§Œ˜”Œº«°§∞Ê±æ£¥£Æ£µ£∞
/* <SecCrypt CPL V3R05> */
 
//  ¥‘¬÷‰ı
inherit SSERVER;
#include <ansi.h>

int cast(object me, object target)
{
   string msg;
   int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;
   int dayphase;

   dayphase =NATURE_D->query_current_day_phase();

   if( !target ) target = offensive_target(me);

   if((int)me->query_skill("spells") < 120
    || (int)me->query_skill("moonshentong",1) < 80)
     return notify_fail("ƒ„ªπ√ª—ßª· ¥‘¬÷‰°£°£°£\n");

   if( !target
   ||      !target->is_character()
   ||      target->is_corpse()
   ||      target==me)
     return notify_fail("ƒ„œÎ∂‘À≠ ©’π ¥‘¬÷‰£ø\n");  

   if(target->query("mark/moon_poison") == 1)
   return notify_fail(target->query("name")+"“—æ≠÷––∞¡À£°\n");  

   if((int)me->query("mana") < 300 )
     return notify_fail("ƒ„µƒ∑®¡¶≤ªπª£°\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("ƒ„Œﬁ∑®ºØ÷–æ´¡¶£°\n");
   //write(dayphase+"\n");
   if (dayphase < 6)
      return notify_fail(" ¥‘¬÷‰÷ª”–“πÕÌ≤≈ƒ‹ ©’π£°\n");

   me->add("mana", -300);
   me->receive_damage("sen", 10);

   msg = HIC
"$NµÕÕ∑ƒ¨ƒ¨ƒÓ∆÷‰Œƒ£¨ ÷÷–Ω•Ω•æ€∆“ªÕ≈π‚«Ú£¨—©∞◊µƒ¡≥≈”À∆∫ı∑¢…‰≥ˆ»·∫Õµƒπ‚√¢°£\n" 
NOR;

   success = 1;
   ap = me->query_skill("spells");
   ap = ap * ap * ap /10 ;
   ap += (int)me->query("combat_exp")/2;
   dp = target->query("combat_exp")/2;
//   if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

   ap2 = (int)me->query_spi();
   dp2 = (int)target->query_spi();

   ap3 = (int)me->query("mana");
   dp3 = (int)target->query("mana");
//   if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
   if( random((ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3))/1000+1) < (dp+2500*dp2+200*dp3)/1000 ) success = 0;

//here we compare current mana. this is important. you need recover to try again.

   if(success == 1 ){
     msg +=  HIR "$nº˚µΩ$NœÈƒ˛÷ÆÃ¨£¨Ωø√¿≤ªø…∑ΩŒÔ£¨–ƒ÷–“ªµ¥£¨»¥≤ª∑¿ƒ«π‚«Ú“ª…¡£¨Õª»ª…‰œÚ$n°£\n" NOR;
     target->set("mark/moon_ice", 1);
     target->apply_condition("moon_poison", ((int)me->query_skill("moonshentong",1)/5));
     me->start_busy(1+random(2)); 
           if( living(target) ) target->kill_ob(me);

   }       
   else {
     msg +=  HIR "$N¡≥…´≤‘∞◊£¨À∆∫ıÃÂ¡¶≤ª÷ß£¨π‚«Ú‘⁄ ÷÷–Ω•Ω•Õ »•°££°\n" NOR;   
     if((int)me->query("mana") > 300 )
        me->add("mana", -300);
     me->apply_condition("moon_poison", ((int)me->query_skill("moonshentong")/10));
   } 

   message_vision(msg, me, target);
   return 1;
}

