// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// taiji-shengong.c 太极神功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < lvl / 10; j++) t *= 2;

//	if ( me->query("gender") == "无性" )
//		return notify_fail("太极神功练的是天地正气，讲的是阴阳调合，以公公无根无性之身，如何修得！\n");

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
			+RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if (lvl > 10 && (int)me->query("sen") < t * 100) 
		return notify_fail("你的侠义正气太低了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

