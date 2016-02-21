// kuihua-xinfa.c 葵花心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("kuihua-xinfa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("学葵花心法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你练了秃驴牛鼻子们的心法，还学葵花心法做什麽！\n");
	if ( me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("taiji-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学葵花心法？！\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("葵花心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"kuihua-xinfa/" + func;
}

