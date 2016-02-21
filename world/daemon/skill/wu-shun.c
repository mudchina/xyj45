// wu-shun.c
//河海天魔摄魂功
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("bellicosity") < ((int)me->query_skill("wu-shun")*50) )
		return notify_fail("你的杀气不够，无法提升河海天魔摄魂功的造诣。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("河海天魔摄魂功只能用学的或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("swordsman") + "/hhu/" + func;
}

