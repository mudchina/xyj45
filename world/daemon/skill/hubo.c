// hubo.c

inherit ITEM;
inherit SKILL;

void create() { seteuid(getuid()); }

void init()
{
    add_action("do_hubo","hubo");
}

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("int") > 25 ) 
           return  notify_fail("你的天性不适合学习双手互博之术!\n" ) ;
	return 1;
}
void do_hubo ( string arg )
{
    write( "你全身放松，坐下来开始运功疗伤。\n" );
    return ;
}
