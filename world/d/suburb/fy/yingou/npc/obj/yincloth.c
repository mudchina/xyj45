// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("银花青底披肩袍", ({ "yincloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是青色上有小花的披肩袍\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
