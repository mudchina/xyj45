//
// xiaowuxiang.c 小无相功
// by secret
// 1997-1-16
//

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xiaowuxiang", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;

	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("你不是僧人，学不了高深的小无相功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学小无相功。\n");

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的小无相功。\n");

	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("要学小无相功，你的表现还不够吧！ \n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
//	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
//	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学小无相功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("小无相功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
