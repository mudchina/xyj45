// 
// 


#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("绣着梅花的浴巾", ({ "towel" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("material", "cloth");
		set("armor_prop/armor", 40);
	}
	setup();
}
