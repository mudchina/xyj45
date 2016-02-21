
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("÷½×Ó", ({ "guzi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"Ò»¿Å¾§äŞÌŞÍ¸µÄÏóÑÀ÷»×Ó\n");
		set("unit", "¶Ñ");
		set("value", 100);
		set("base_unit", "Á£");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(88);
	init_throwing(1);
	setup();
}
