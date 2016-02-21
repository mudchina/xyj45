// 
// 

inherit ITEM;
void create()
{
	set_name("神妃", ({ "神妃","shenji", "神妃像" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",
			"一个着衣配坐的神妃像，上面好象刻着一些字。\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"incarnation",	
			"exp_required":	0,		
			"sen_cost":		30,	
			"difficulty":	20,	
			"max_skill":	90		
		]) );
	}
}
