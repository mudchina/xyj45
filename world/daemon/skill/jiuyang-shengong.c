// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// jiuyang-shengong.c 九阳神功
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");

	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 20)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练九阳神功。\n");

	me->receive_damage("kee", 10);
	me->receive_damage("force", 10);
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
