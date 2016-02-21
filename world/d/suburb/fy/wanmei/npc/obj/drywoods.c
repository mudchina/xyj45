#include <weapon.h>
inherit THROWING;
void create()
{
	set_name("¸ÉÄ¾²ñ", ({ "woods", "dry woods" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("base_unit", "Ìõ");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(2);
	setup();
}
