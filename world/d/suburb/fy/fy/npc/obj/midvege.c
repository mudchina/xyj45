// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("胡萝卜", ({ "carrot" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条红红，又香又脆的胡萝卜\n");
		set("unit", "个");
		set("value", 35);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
