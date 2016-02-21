// Tie@fengyun
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("雅乌古剑", ({ "darksword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起古朴而又锋利的剑\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(35);
	setup();
}
