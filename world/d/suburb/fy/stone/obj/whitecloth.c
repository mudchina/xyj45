// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW "点点血斑的白袍" NOR, ({ "whitecloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是件昂贵的白袍但上面布满血斑。\n");
		set("value", 10000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
