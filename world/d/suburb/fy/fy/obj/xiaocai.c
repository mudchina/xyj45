inherit F_FOOD;
inherit ITEM;

void create()
{
	string *name = ({"花生","小黄瓜","罗卜条"});
	set_name(name[random(sizeof(name))], ({ "small dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘小菜。\n");
		set("unit", "盘");
		set("value", 2);
		set("food_remaining", 5);
		set("food_supply", 6);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
	if( random(2))
        set_name("崩了口的小碟儿", ({"diezi"}));
	else
        set_name("小碟儿", ({"diezi"}));
	set("value",0);
        set("long", "一只小盘子。\n");
        return 1;
}
