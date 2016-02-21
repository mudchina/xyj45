// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(  "魅影神带" , ({ "ghosty girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 7000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 5);
	}
	setup();
}
