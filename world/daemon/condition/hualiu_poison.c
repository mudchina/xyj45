// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "的花柳毒又发作了．．。\n",
			environment(me), me);
	} else if( duration > limit/2 ) {
		tell_object(me, "你觉得全身又痛又痒。\n");
		message("vision", me->name() + "的花柳毒又发作了，满面痛苦后悔的表情。\n",
			environment(me), me);
		me->receive_damage("sen", 10);
	} else if( duration > limit/4 ) {
		tell_object(me, "你觉得全身又痛又痒。\n");
		message("vision", me->name() + "的花柳毒又发作了，满面痛苦后悔的表情。\n",
			environment(me), me);
		me->receive_damage("sen", 3);
		me->receive_healing("gin", 10);
		me->receive_healing("kee", 15);
	}

	me->apply_condition("hualiu_poison", duration - 1);
	if( !duration ) return 0;
	return 1;
}
