// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// test.c
#include <combat.h>
#include <weapon.h>
#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob, second, first;
   string attack_skill, martial_skill, first_skill;


   ob = present(arg, environment(me));
   if(!ob) return notify_fail("Can't find target.\n");

//   SKILL_D("celestial")->hit_ob(me, ob, 50, 20);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
/*
   if( me->query_temp("weapon")){
     if( first=me->query_temp("weapon")){
        first_skill=first->query("skill_type");
     }
     if( me->query_skill_mapped(attack_skill) ){
        first_skill=me->query_skill_mapped(attack_skill);
     }
   }
*/
   if( me->query_temp("weapon")){
     first=me->query_temp("weapon");
     if( me->query_temp("weapon_second")){
        second=me->query_temp("weapon_second");
/*
        first->delete("equipped");
        second->set("equipped", "wielded");
        me->set_temp("weapon", second);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->set_temp("weapon", first);
        second->set("equipped", "second_wield");
        first->set("equipped", "wielded");
*/
     }
   }

   if( me->query_temp("weapon_second") ){
     if( second=me->query_temp("weapon_second") ){
        attack_skill=second->query("skill_type");
        write("Attack_skill, skill_type :" +attack_skill+"\n");
     }
     first->delete("equipped");
     second->set("equipped", "wielded");
     me->set_temp("weapon", second);
     me->reset_action();
     if( martial_skill=me->query_skill_mapped(attack_skill)){
        write("Martial_skill, attack_skill :" + martial_skill+"\n");
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
//        SKILL_D(martial_skill)->hit_ob(me, ob, 30);
     }else{
        write("No special skills, Weapon hit.\n");
        me->set_temp("weapon", second);
        SKILL_D(attack_skill)->hit_ob(me, ob, 30);
        me->set_temp("weapon", first);
     }
     second->set("equipped", "second_wield");
     first->set("equipped", "wielded");
     me->set_temp("weapon", first);
     me->reset_action();
   }

    printf("wizard level: %d   status: %s\n", wiz_level(ob), wizhood(ob));
   return 1;
}

int help(object me)
{
write(@HELP
指令格式 : test <某人>

用来测试武功技能的强弱。
HELP
    );
    return 1;
}
