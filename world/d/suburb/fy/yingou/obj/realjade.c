// movebook.c

inherit ITEM;

void create()
{
	set_name("罗刹牌", ({ "luosha" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("for_bandit",1);
		set("long",
			"这块真罗刹牌上正刻得是天师正道\n");
		set("value", 0);
		set("material", "stone");
		set("skill", ([
			"name": 		"taoism",	
			"exp_required":	20000,				
			"sen_cost":		20,				
			"difficulty":	40,		
			"max_skill":	40		
		]) );
	}
}
