// shenxing-baibian.c 神行百变

inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「行云流水」，身不倾，脚不移，身体如行云流水般直滑出丈余。\n",
	"dodge"  : 10
]),
([	"action" : "$n一式「潜音夜行」，忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。\n",
	"dodge"  : 20
]),
([	"action" : "$n一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
	"dodge"  : 30
]),
([	"action" : "$n一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。\n",
	"dodge"  : 40
]),	
([	"action" : "$n一式「凌波微步」，左踏巽，右转乾，身行一晃，便到几丈远的地方。\n",
	"dodge"  : 50
]),
([	"action" : "$n一式「更上层楼」，身在空中，左脚在右足上一点，从$N头顶腾空而过。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「仙子出水」，长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。\n",
	"dodge"  : 70
]),
([	"action" : "$n一式「峰回路转」，身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「临行秋波」，身行倏的从$N的眼前直绕到身后，$N瞪大了两眼，不明所以。\n",
	"dodge"  : 90
]),
([	"action" : "$n一式「浪子回头」，身行倏的从$N的眼前飘过，长发一甩，潇洒之极。\n",
	"dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shenxing-baibian");


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
	if( (int)me->query("ke") < 40 )
		return notify_fail("你的体力太差了，不能练神行百变。\n");
	me->receive_damage("kee", 20);
	return 1;
}
