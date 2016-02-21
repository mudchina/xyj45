#include <weapon.h>
inherit AXE;
void create()
{
	set_name("订作的", ({ "order" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("no_drop",1);
		set("no_get",1);
		set("owner","fengyun");
		set("rigidity",300);
		set("material", "iron");
		set("long", "这是一把黑油油的铁斧，份量很重。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	init_axe(30);
	setup();
}
