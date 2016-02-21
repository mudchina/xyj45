// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("金花黄底飞凰袍", ({ "jincloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是件黄色，上面绣满金花和飞舞的凤凰袍\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
