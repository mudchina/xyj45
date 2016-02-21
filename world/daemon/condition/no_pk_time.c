// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// pk_counter.c
// by mon. 9/22/97

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        object env=environment(me);
   
   if(env) {
       if(!env->query("no_fight") && !env->query("no_magic"))
          me->apply_condition("no_pk_time", duration - 1);
       // can't hide in safe room to count hours.
   }

//   write("PK:"+duration+":"+me->query_condition("no_pk_time")+"\n");

   if( duration < 1 ) return 0;

   return CND_CONTINUE;
}
