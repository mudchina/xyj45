// 
// 


#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("砍林刀", ({ "lindao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 60);
		set("jungle",1);
		set("material", "iron");
		set("long", "这是一寻常的砍林刀，专门用来砍小树和灌木．\n");
		set("wield_msg", "$N抽出一把黑油油的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	init_blade(5);
	setup();
}
