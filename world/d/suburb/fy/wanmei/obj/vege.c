// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        string *order=({"小白菜", "小青菜", "大青菜", "大白菜",
"韭菜","青豆","豌豆","绿豆苗"});
	set_name(order[random(8)], ({ "vegetable" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一棵可人的青菜\n");
		set("unit", "棵");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
