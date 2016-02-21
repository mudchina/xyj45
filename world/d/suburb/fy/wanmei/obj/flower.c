#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("路边的野花", ({ "wildflower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"路边的野花，发出一股淡淡的香气。\n");
		set("unit", "把");
		set("base_unit", "朵");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(2);
	setup();
}
