// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("嫩藕", ({ "nenou" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一段洗得干干净净的嫩藕\n");
		set("unit", "段");
		set("value", 1000);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
