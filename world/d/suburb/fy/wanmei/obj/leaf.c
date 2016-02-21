#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("©щ╩ф╣др╤", ({ "deadleaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "╟я");
		set("base_unit", "уе");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(2);
	setup();
}
