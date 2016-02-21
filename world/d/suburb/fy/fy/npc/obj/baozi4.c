// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("生煎包", ({ "shengbao" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷、热腾腾的大包子。\n");
		set("unit", "个");
		set("value", 60);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}
