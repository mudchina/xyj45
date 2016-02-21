// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("风云差服", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是风云城官府用衣服。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
