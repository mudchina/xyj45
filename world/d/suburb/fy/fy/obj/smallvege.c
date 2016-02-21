// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小白菜", ({ "small cabbage" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条水灵灵的小白菜\n");
		set("unit", "个");
		set("value", 15);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
