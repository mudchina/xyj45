inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("糙面", ({ "caomian" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一团发黄的糙面\n");
		set("unit", "团");
		set("value", 5);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
}
