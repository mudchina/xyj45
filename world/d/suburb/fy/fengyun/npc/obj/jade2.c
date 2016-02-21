// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("玉花", ({ "jade flower"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个翠绿欲滴的玉花\n");
		set("unit", "个");
		set("value", 20000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");


	}
	setup();
}

