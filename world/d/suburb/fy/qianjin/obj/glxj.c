inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("高丽香蕉", ({ "glxj", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘名厨烹调的上好大菜。\n");
		set("unit", "盘");
		set("value", 200000);
		set("food_remaining", 3);
		set("food_supply", 10);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
        set_name("小碟儿", ({"xiaodie"}));
	set("value",20);
        set("long", "一只蓝底儿雕花的景泰蓝小碟儿。\n");
        return 1;
}
