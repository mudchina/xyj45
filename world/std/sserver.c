// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// sserver.c

inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
   int sz;
   object *enemy;

   enemy = me->query_enemy();
   if( !enemy || !arrayp(enemy) ) return 0;

   sz = sizeof(enemy);
   if( sz > 4 ) sz = 4;

   if( sz > 0 ) return enemy[random(sz)];
   else return 0;
}
