// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("Îèµû²ÊÉÀ", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼ş");
		set("long", "Ò»¼şÎå²Ê°ßÀ»µÄÎèµû²ÊÉÀ\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 3);
	}
	setup();
}
