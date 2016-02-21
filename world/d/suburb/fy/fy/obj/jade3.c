
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("玉指", ({ "jade ring"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个翠绿欲滴的玉指\n");
		set("unit", "个");
		set("value", 10000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
		set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");


	}
	setup();
}

