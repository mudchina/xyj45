// changelaw.c

inherit SKILL;

int valid_enable(string usage) { return usage=="literate"; }

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	return 1;
}
int effective_level() 
{ return 25;}

int learn_bonus()
{
	return -50;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 10;
}


