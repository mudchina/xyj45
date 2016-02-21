// yunlong-shenfa 云龙身法

inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「龙腾虎跃」，身行一转，猛的跳向一旁,躲过了$N的功势。\n",
	"dodge"  : 10
]),
([	"action" : "$n一式「沙场点兵」，双臂置于身后，不急不缓，昂首从$N眼前跨过。\n",
	"dodge"  : 20
]),
([	"action" : "$n一式「风雨同舟」，不退反进，一下子绕到了$N的身后。\n",
	"dodge"  : 30
]),
([	"action" : "$n一式「养精蓄锐」，缓缓的向后一退，轻松让过了$N的凌厉攻势。\n",
	"dodge"  : 40
]),
([	"action" : "$n一式「无心插柳」，左手一扬，身行一晃，便向右飘出丈远。\n",
	"dodge"  : 50
]),
([	"action" : "$n一式「苍鹰搏兔」，身体如一只苍鹰，呼的一声从$N的眼前飞过。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「九龙在天」，忽的拔地而起，在半空中一转，已落到几丈远的地方。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「瀑落九天」，全身化为一道白影，忽的一个空翻，从左边飘到右边。\n",
	"dodge"  : 90
]),
([	"action" : "$n一式「幻眼云烟」，身形陡地变得飘忽不定，令$N无法看清。\n",
	"dodge"  : 100
]),
([	"action" : "$n一式「九天揽月」，宛若一条矫矢苍龙，倏的拔地而起，令$N不敢仰视。\n",
	"dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("yunlong-shenfa");

	if (level < 70 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
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
	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力太差了，不能练云龙身法。\n");
	me->receive_damage("kee", 20);
	return 1;
