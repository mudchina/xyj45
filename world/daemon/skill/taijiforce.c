// taijiforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("太极心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("wudang") + "/taijiforce/" + func;
}
 
int effective_level() { return 13;}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 30;
}
int black_white_ness()
{
	return 50;
}

