
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("杀威棒" , ({ "shawei", "bang" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长的木制杀威棒，两头红色。\n");
		set("value", 620);
		set("material", "wood");
		set("wield_msg", "$N拿出一根两头红色的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(33);
	setup();
}
