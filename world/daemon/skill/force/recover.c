// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q;

	if (me != target)
		return notify_fail("你只能用内功调匀自己的气息。\n");

	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

	q = (int)me->query("eff_kee") - (int)me->query("kee");
	if (q < 10)
		return notify_fail("你现在气力充沛。\n");
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("force") < n) {
		q = q * (int)me->query("force") / n;
		n = (int)me->query("force");
	}

	me->add("force", -n);
	me->receive_heal("kee", q);
	
        message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
