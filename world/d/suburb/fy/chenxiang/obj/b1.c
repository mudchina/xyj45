// 
// 


#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("镰刀", ({ "liandao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 50);
		set("material", "iron");
		set("long", "这是一寻常的镰刀，份量大约四、五斤重。\n");
		set("wield_msg", "$N抽出一把黑油油的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	init_blade(15);
	setup();
}
