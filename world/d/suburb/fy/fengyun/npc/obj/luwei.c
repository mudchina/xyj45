inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("卤味儿", ({ "luwei", "lu" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘上好的卤味儿。\n");
		set("unit", "盘");
		set("value", 2000);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
        set_name("小盘子", ({"panzi"}));
	set("value",200);
        set("long", "一只蓝底儿雕花的盘子。\n");
        return 1;
}
