#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name( HIR "火龙赤皮" NOR, ({ "dragonskin" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long",
			"一块布满暗红色的鳞皮\n");
		set("value", 7000);
		set("material", "cloth");
		set("skill", ([
			"name": 		"yoga",	
			"exp_required":	1000000,				
			"sen_cost":		100,				
			"difficulty":	40,		
			"max_skill":	150		
		]) );
		set("armor_prop/armor",10);
		}
	setup();
}
