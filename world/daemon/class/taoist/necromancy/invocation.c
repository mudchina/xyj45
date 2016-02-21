// invocation.c

inherit SSERVER;
#define MAX_GUARD 4
int cast(object me, object target)
{
	object soldier;
	int	spells;

        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("你的法术不够高！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤天将！\n");
	
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 60 )
		return notify_fail("你的精神无法集中！\n");
        if( me->query_temp("max_guard") > MAX_GUARD )
		return notify_fail("你已经召唤太多天兵鬼卒了！\n");

	message_vision("$N喃喃地念了几句咒语。\n", me);

	me->add("mana", -50);
	me->receive_damage("sen", 30);

	if( random(me->query("max_mana")) < 200 ) {
		message("vision", "但是什麽也没有发生。\n", environment(me));
		return 1;
	}

	seteuid(getuid());
	if( random(spells) > (spells/2))
		soldier = new("/obj/npc/heaven_soldier");
	else
		soldier = new("/obj/npc/hell_guard");

	soldier->move(environment(me));
	soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->add_temp("max_guard",1);
	return 1;
}
