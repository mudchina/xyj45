// 
// 

#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("毗沙门塔", ({ "staff" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 500);
		set("material", "stone");
		set("long", "一条极沉的塔。\n");
		set("weapon_prop/karma",3);
	}
	init_staff(5);
	setup();
}
