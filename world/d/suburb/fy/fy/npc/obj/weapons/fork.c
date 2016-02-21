#include <weapon.h>
inherit FORK;
void create()
{
	set_name("¶©×÷µÄ", ({ "order" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
                set("no_drop",1);
                set("no_get",1);
                set("owner","fengyun");
                set("rigidity",300);
		set("material", "steel");
	}
	init_fork(30);
	setup();
}
