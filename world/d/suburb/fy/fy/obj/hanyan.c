
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(  "长杆旱烟枪" , ({ "hanyan" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把烟锅又拳头大小的长杆旱烟枪。\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_dagger(25);
	setup();
}
