// 
// 

#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("赖吒刀", ({ "blade" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "stone");
		set("long", "一把极沉的石刀。\n");
		set("weapon_prop/courage",3);
	}
	init_blade(5);
	setup();
}
