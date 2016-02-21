// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("薯条", ({ "st" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一包香喷喷的薯条。\n");
		set("unit", "个");
		set("value", 15);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
