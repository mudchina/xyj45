// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bow.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_bow(int damage, int flag)
{
   if( clonep(this_object()) ) return;

   set("weapon_prop/damage", damage);
   set("flag", flag|SECONDARY );
   set("skill_type", "blade");
   set("apply/skill_type", "archery");
   if( !query("actions") ) {
     set("actions", (: call_other, WEAPON_D, "query_action" :) );
     set("verbs", ({ "slash", "slice", "hack", "chop" }) );
   }
}
