// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// bonze_drug.c

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("bonze_drug", duration - 1);
	return 1;
}
