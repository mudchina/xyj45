// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("银红散花裙", ({ "silver skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件银边淡红缀满蓝花的裙\n");
		set("material", "cloth");
		set("value", 10000);
		set("armor_prop/armor", 3);
	}
	setup();
}
