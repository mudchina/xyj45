// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
   me->receive_wound("kee", 10);
   me->receive_damage("sen", 10);
   me->set_temp("death_msg","蛇毒发作死了。\n");
   me->apply_condition("snake_poison", duration - 1);
   tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );
   if( duration < 1 ) return 0;
   return 1;
}
