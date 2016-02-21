// tea_leaf.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("茶花", ({ "teaflower", "flower" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"洁白的山茶花，发出一股淡淡的香气。\n");
		set("unit", "把");
		set("base_unit", "朵");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(2);
	init_throwing(2);
	setup();
}
