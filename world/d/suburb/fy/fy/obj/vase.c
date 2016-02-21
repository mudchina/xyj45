
inherit ITEM;

void create()
{
	set_name("白玉瓶", ({ "vase" , "白玉瓶"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个制作精美的上等白玉瓶\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
