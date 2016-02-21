// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("小花裙", ({ "xiaoskirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件缀满蓝色小花的裙子\n");
		set("material", "cloth");
		set("value", 10000);
		set("armor_prop/armor", 3);
	}
	setup();
}
