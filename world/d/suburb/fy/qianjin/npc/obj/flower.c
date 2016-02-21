
inherit ITEM;

void create()
{
	set_name("花卉", ({ "flower" , "花卉"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "丛");
		set("long", "一丛茂盛的花卉．\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


