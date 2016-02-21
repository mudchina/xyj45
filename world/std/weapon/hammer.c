// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hammer.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_hammer(int damage, int flag)
{
   if( clonep(this_object()) ) return;

   set("weapon_prop/damage", damage);
   set("flag", flag );
   set("skill_type", "hammer");
   if( !query("actions") ) {
     set("actions", (: call_other, WEAPON_D, "query_action" :) );
     set("verbs", ({ "bash", "crush", "slam" }) );
   }
}

