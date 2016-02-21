// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//cast function: qiankun.c 袖里乾坤。
//need to be activated by 镇元大仙 to use this cast...weiqi, 
//weiqi, mon 1/98

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int success, ap, dp;
   object sleeveroom,sleeve;
   string sname;
   object env, *inv;
   int size,i;

   seteuid(getuid());

   if( me->query("spell_qiankun_on") != 1 )
     return notify_fail("你还不会袖里乾坤。\n");

//   if( !target ) target = offensive_target(me);

        if(!target) 
        {
          //see if I am fighting someone...this is useful for NPC...
          if(  (offensive_target(me)) ) target = offensive_target(me);
      else
         {
     // then take stuff out.
     sleeveroom=load_object("/d/wiz/sleeveroom");
     if(!sleeveroom) return notify_fail("No sleeve space found.\n");

          sname=me->query("id")+"'s sleeve";
          if(!sleeve=present(sname,sleeveroom)) {
             message_vision(
        "$N将大袖迎空一甩，但是里面什么也没有。\n",me);
        return 1;
          }

     size=sizeof(inv=all_inventory(sleeve));
     if(!size) {
             message_vision(
        "$N将大袖迎空一甩，但是里面什么也没有。\n",me);
        return 1;
          }

     msg="$N将大袖迎空一甩，";
     for(i=0;i<size;i++) {
       if(inv[i]->is_character())
         msg+="$n扑通一声摔倒在地上。\n";
            else
         msg+="$n嗵地一声砸在地上。\n";

            env=environment(me);
            while(!(inv[i]->move(env))) env=environment(env);

       message_vision(msg,me,inv[i]);
       msg="";
     }
          return 1;
   }
       }

   if( !target
   || !target->is_character()
   || target->is_corpse()
   || target==me)
     return notify_fail("你要对谁施展袖里乾坤？\n");

   if( (int)me->query("mana") < 400 )
     return notify_fail("你的法力不够了！\n");

   if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
     return notify_fail("你现在头脑不清醒，哪里使得出袖里乾坤！\n");

   if( random(me->query("max_mana")) < 50 ) {
     write("你失败了！\n");
     return 1;
   }

   msg =  HIR "$N喃喃地念了几句咒语，突然大袖一挥朝$n罩了过去！\n" NOR;
   message_vision(msg, me, target);
   
   target->kill_ob(me);
   me->kill_ob(target);


   success = 1;
   ap = me->query_skill("spells");
   ap = ap * ap * ap /10 ;
   ap += (int)me->query("combat_exp");
   ap = 3*ap; 
   dp = target->query("combat_exp");
   if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

   ap = (int)me->query("max_mana");
   dp = (int)target->query("max_mana");
   if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to success.

   if(success == 1 )
   {
     me->add("mana", -400);
   
           sleeveroom=load_object("/d/wiz/sleeveroom");
     if(!sleeveroom) return notify_fail("No sleeve space found.\n");

                sname=me->query("id")+"'s sleeve";
     if(!sleeve=present(sname,sleeveroom)) {
                  sleeve=new("/d/obj/fabao/sleeve");
       if(!sleeve) return notify_fail("No sleeve found.\n");

       sleeve->set_max_encumbrance(300000);
       //this corresponding to about 4 people.
       //should make this depends on the spells level of
       //a player, so higher ppl can carry more.

       sleeve->set_name(
         me->query("name")+"的衣袖中",({sname,"sleeve"}));
                  sleeve->set("short",
         me->query("name")+"的衣袖中");
       if(!sleeve->move(sleeveroom)) 
         return notify_fail("Failed to move sleeve.\n");
     }

     if(target->move(sleeve)) {
       msg =  HIR "结果嗖的一声$n被装了进去。\n" NOR;
       message_vision(msg, me, target);
                } else {
                  msg=HIR"结果$n只是摇晃了一下，又不动了。\n" NOR;
       msg+="$n对$N来说太沉了。\n";
       message_vision(msg, me, target);
     }
     
   }
   else 
   {
     msg =  HIR "结果被$n法力一逼，差点罩住$N自己的脑袋。\n" NOR;
     message_vision(msg, me, target);

     me->add("mana", -400);
   } 

   return 3+random(5);
}

