
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name( "摺扇" , ({ "zheshan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当精致的摺扇\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n展开握在手中扇了两下。\n");
		set("unwield_msg", "$N将手中的$n合起收入袖中。\n");
	}
	init_dagger(5);
	setup();
}
