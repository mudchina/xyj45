// bag.c

inherit ITEM;

void create()
{
	set_name("精钢园桶", ({ "steel tube" }) );
	set_weight(50);
	set_max_encumbrance(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个精钢园桶\n");
		set("value", 100);
	}
}

int is_container() { return 1; }
