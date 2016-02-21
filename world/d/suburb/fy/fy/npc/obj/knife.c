
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("飞刀", ({ "feidao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一把长短刚好的柳叶飞刀\n");
		set("unit", "堆");
		set("value", 1000);
		set("base_unit", "把");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(10);
	setup();
}
