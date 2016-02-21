// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// huashan-neigong.c 华山内功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int i = (int)me->query_skill("taiji-shengong", 1);
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	if ((int)me->query("sen") < (int)pow(i/10, 2) * 100)
		return notify_fail("你的神太低了。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D(__DIR__"taiji-qigong/") + func;
}

