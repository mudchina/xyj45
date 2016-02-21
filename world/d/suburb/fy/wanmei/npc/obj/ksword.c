#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name( HIG "青衣刺" NOR, ({ "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把剑身发青的剑。\n");
		set("value", 400000);
		set("material", "steel");
		set("rigidity", 20000);
	}
	init_sword(5);
	setup();
}
