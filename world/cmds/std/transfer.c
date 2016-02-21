// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me)
{
	int exp, pot, tpot;
	tpot = (int) me->query("potential");
	pot = (int) me->query("potential")- (int) me->query("learned_points");
	exp = (int) me->query("combat_exp");
	exp = exp+pot * 2;
	me->set("combat_exp",exp );
	me->set("potential", tpot - pot);	
	write("ＯＫ\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : transfer
 
这个指令可以让你将潜能转为经验（１：２）.
 
HELP
    );
    return 1;
}
