// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("血肠", ({ "xuechang" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一段可口的血肠\n");
		set("unit", "段");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
