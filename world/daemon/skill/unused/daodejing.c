// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//daodejin.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼道德经。\n");
        return 1;
}

