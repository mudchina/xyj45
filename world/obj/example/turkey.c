// chicken_leg.c
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("香喷喷的大火鸡", ({ "fried turkey", "turkey"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只烤得香喷喷的大火鸡，感恩节快乐！！\n");
		set("unit", "只");
		set("food_remaining", 40);
		set("food_supply", 100);
	}
}
