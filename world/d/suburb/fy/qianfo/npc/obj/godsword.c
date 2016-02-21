// 
// 

#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("青色宝剑", ({ "sword" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "stone");
		set("long", "一把极沉的青色宝剑。\n");
		set("weapon_prop/agility",1);
	}
	init_sword(5);
	setup();
}
