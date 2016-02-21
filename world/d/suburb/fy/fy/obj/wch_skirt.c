// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIY "五" + HIR "彩" NOR + "紧身裙", ({ "miniskirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件五彩丝编成的紧身裙\n");
		set("material", "cloth");
		set("value", 10000);
		set("armor_prop/armor", 3);
	}
	setup();
}
