// 
// 

inherit FORCE;
int valid_enable(string usage) 
{ 
        return usage=="cursism" ||
	       usage == "force" ;

}
int valid_learn(object me)
{
	return 1;
}

string curse_curses_file(string curse)
{
	return CLASS_D("diabloist") + "/celecurse/" + curse;
}
string exert_function_file(string func)
{
        return CLASS_D("diabloist") + "/celecurse/" + func;
}
int practice_skill(object me)
{	
	return 0;
}
int effective_level() { return 10;}
int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -50;
}

