//
// shenkong-xing.c 身空行
// designed by secret(秘密)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$n使出一招「心空」，身体向侧后飘去 \n",
        "dodge" : 15,
]),
([      "action" : "$n使出一招「誓言空」，双足一点，跃至数丈之外 \n",
        "dodge" : 30,
]),
([      "action" : "$n使出一招「莲空」，身形一变，滑至$N身后 \n",
        "dodge" : 45,
]),
([      "action" : "$n大吼一声，使出一招「大安空」，从$N头顶越过 \n",
        "dodge" : 60,
]),
([      "action" : "$n使出一招「佛空」，如轻鸿般飘去，瞬间又闪至$N面前 \n",
        "dodge" : 75,
]),
([      "action" : "$n使出一招「金刚空」，顿时$N周围都是$n的身影 \n",
        "dodge" : 90,
]),
});


mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shenxingkong");

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	if (level < 30 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练习身空行。\n");
	me->receive_damage("qi", 20);
	return 1;
}
