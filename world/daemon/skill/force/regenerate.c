// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");
	
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

	me->add("force", -20);
	me->receive_heal("gin", (int)me->query_skill("force") / 3);
	
        message_vision("$N深深吸了几口气，精神看起来好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

