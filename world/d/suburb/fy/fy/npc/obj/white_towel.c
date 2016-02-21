
#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("白毛巾", ({ "white towel", "towel" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条干干净净的大白毛巾\n");
		set("unit", "条");
		set("value", 5000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", -50);
		set("armor_prop/unarmed",-30);
	}
	setup();
}

