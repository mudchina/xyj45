#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("¶©×öµÄ", ({ "order" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
                set("no_drop",1);
                set("owner","fengyun");
                set("no_get",1);
		set("material", "wood");
		set("armor_prop/armor", 10);
	}
	setup();
}
