// sttormdance.c

inherit SKILL;

string *dodge_msg = ({
	"但是$n身法轻灵，翩翩地飘了开去！\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("七宝天岚舞只有女性才能练。\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("你的灵性不够，没有办法练七宝天岚舞。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练七宝天岚舞。\n");
	me->receive_damage("sen", 30);
	return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}

