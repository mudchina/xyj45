// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/daemon/class/force/" + func;
}


