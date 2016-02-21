// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("卤蛋", ({ "egg" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大卤蛋\n");
		set("unit", "个");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
