// 云龙神功

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("yunlong-xinfa", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("yunlong-shengong", 1);

	if ( me->query("gender") == "无性" && nh > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的云龙神功。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的云龙心法修为不够，无法领会更高深的云龙神功。\n");

	if ( nf < 40)
		return notify_fail("你的基本内功火候还不够，无法领会云龙神功。\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
//	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学云龙神功？！\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("云龙内功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunlong-shengong/" + func;
}
