// counterattack.c

#include <ansi.h>

inherit SSERVER;
void surekill(object me, object target);
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31mĞ¡Àî·Éµ¶[37mÖ»ÄÜ¶ÔÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");
	if((int) me->query_skill("feidao",1) <= 200)
		return notify_fail("ÄãµÄ·Éµ¶¾ø¼¼»¹²»¹»¾«´¿£¬²»ÄÜ·¢³öĞ¡Àî·Éµ¶¡£\n");

	message_vision(RED"$NÄ¿²»×ª¾¦µØ¶¢×Å$n£¬×¼±¸·¢³öÖÂÃüÒ»»÷¡£\n"NOR,me,target);
msg = HIY "$NÊ¹³ö·Éµ¶¾ø¼¼ÖĞÀıÎŞĞé·¢µÄ" + HIR "Ğ¡Àî·Éµ¶" +HIY "£¬$nÖ»¾õµÃÑÛÇ°Ò»»¨£¬ÑÊºíÒÑ±»¶Ô´©¶ø¹ı£¡£¡£¡" ;
msg +=  "\nÒ»¹ÉÑª¼ıÅçÓ¿¶ø³ö£®£®$nµÄÑÛ¾¦ËÀÓã°ãµÄÍ»ÁË³öÀ´£®£®\n" NOR;

	message_vision(msg, me, target);
		target->die();
	return 1;
}
