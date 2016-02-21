
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( HIR "绑着一块木头的锈铁片" NOR, ({ "rustysword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把绑着一块木头的锈铁片，看起来象玩具．\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N把别在腰间$n拔出握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}
	init_sword(85);
	setup();
}
