// 
// 

inherit ITEM;
void create()
{
	set_name("残棋", ({ "残棋","canqi", "一局未完的残棋" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "局");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"doomforce",	
			"exp_required":	0,		
			"sen_cost":		30,	
			"difficulty":	20,	
			"max_skill":	30		
		]) );
	}
}
