// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("带血纱衣", ({ "shayi" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件薄带血的纱衣\n");
		set("material", "cloth");
		set("value", 10);
	}
	setup();
}
