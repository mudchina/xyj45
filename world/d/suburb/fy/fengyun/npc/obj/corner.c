
inherit ITEM;

void create()
{
	set_name("墙角", ({ "corner" , "墙角"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个布满了灰尘的墙角\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


