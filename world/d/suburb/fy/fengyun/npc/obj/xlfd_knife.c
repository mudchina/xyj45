
#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(RED "小李飞刀" NOR, ({ "flying blade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一把人见人怕的小李飞刀\n");
		set("unit", "堆");
		set("value", 1000);
		set("base_unit", "把");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(100);
	setup();
}
