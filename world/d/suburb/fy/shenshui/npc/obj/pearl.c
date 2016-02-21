// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("大珍珠", ({ "big pearl", "pearl" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"价值连城的夜明珠，发出一种蓝幽幽的光泽。\n");
		set("unit", "串");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 1000);
	}
	set_amount(3);
	init_throwing(7);
	setup();
}
