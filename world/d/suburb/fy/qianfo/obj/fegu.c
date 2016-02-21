// 
// 

#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("Í­·ð¹Ä", ({ "fegu" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¸ö");
		set("value", 500);
		set("material", "wood");
		set("long", "Ò»¸öÂÌ°ß°ßµÄÍ­·ð¹Ä\n");
		set("weapon_prop/karma",1);
	}
	init_hammer(5);
	setup();
}
