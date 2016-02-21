// swordjab.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
	string msg;
	int i,b;
        if (me->query("force")<10) return notify_fail("你内力不够了！！\n");
	if( !target ) target = offensive_target(me);

	/*if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。\n");*/

	msg = HIR "$N使出河海内功的精华----天魔吸魂大法！\n";
            b=me->query_skill("force");
	if( random(100) <(b/2)) {
	//	msg += "$p已显吃力。\n" NOR;
	//	for (i=0; i<random (3)+1; i++)
        msg+=HIG "$p大叫一声不好！精气神正不断外泻！！！！\n" NOR;
                  i=target->query("kee");i=i*b/150;
              if (i>0) {      target->add("kee",-i);me->add("kee",i);}
                  i=target->query("sen");i=i*b/150;
              if (i>0){      target->add("sen",-i);me->add("sen",i);} 
                 i=target->query("gin");i=i*b/150;
             if (i>0)  {     target->add("gin",-i);me->add("gin",i);}


	//		COMBAT_D->do_attack(me, target, me->query("weapon"));
		} 
	    else {
		msg +=HIB "但是被$p从容化解了，$p大吼一声：“你敢暗算我？，纳命来！”\n" NOR;
                        target->kill_ob(me);	     
                        //   me->kill_ob(target);
	}
	message_vision(msg, me, target);
        
	me->add("force",  -10);

	return 1;
}
