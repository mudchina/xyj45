
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("黑玉发簪", ({ "pin"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个黑里透着翠绿的玉发簪\n");
		set("unit", "个");
		set("value", 3000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

		set("female_only", 1);

	}
	setup();
}

