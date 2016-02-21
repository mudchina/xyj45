// drainerbolt.c

#include <ansi.h>

inherit SSERVER;

int thunderspell(object me, object obj)
{
	int	spi, kar, kee, damage, spells;

	message_vision(YEL "\n一个闪电向$N的头上打来，\n" NOR, obj);
	obj->receive_damage("sen", 0, me);
	spells = me->query_skill("spells");
	if(obj->is_ghost()==1) {
		message_vision(RED "$N惨叫了一声，化为了灰烬！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(RED "$N惨叫了一声，化为了一滩血水！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->query("race")=="野兽") {
		kar = obj->query("kar");
		spi = obj->query("spi");
		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
		if(damage > 35) damage = 35;
		if(damage != 0) {
			message_vision(RED "正打在了$N的头上！\n" NOR, obj);
			obj->receive_damage("kee", damage, me);
	 		COMBAT_D->report_status(obj);
			if( !obj->is_fighting(me) ) {
                		if( living(obj) ) {
                        		if( userp(obj) ) 
						obj->fight_ob(me);
					else
						obj->kill_ob(me);
                		}
                		me->kill_ob(obj);
        		}
		} else 
			message_vision(RED "但被$N躲过了！\n" NOR, obj);
		return 1;
	}
	kar = obj->query("kar");
	spi = obj->query("spi");
	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 0;
	if(damage > 20) damage = 20;
	if(damage != 0 && random(kar) < 20) {
		message_vision(RED "正打在了$N的头上！\n" NOR, obj);
		obj->receive_damage("kee", damage, me);
 		COMBAT_D->report_status(obj);
		if( !obj->is_fighting(me) ) {
               		if( living(obj) ) {
                       		if( userp(obj) ) 
					obj->fight_ob(me);
				else
					obj->kill_ob(me);
               		}
               		me->kill_ob(obj);
       		}
	} else 
			message_vision(RED "但被$N躲过了！\n" NOR, obj);
	return 1;
	
}
int cast(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;

	if((int)me->query_skill("spells") < 200 )
		return notify_fail("你的法术不够高！\n");

	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的体力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -200);
	me->receive_damage("sen", 90);

	msg = YEL "$N脚踩天罡步，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
	msg = msg + RED "猛地双手一挥，天上打下无数闪电！\n\n" NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(5);
	return 1;
}

