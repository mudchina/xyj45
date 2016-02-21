inherit ITEM;
void create()
{
	set_name("小河", ({ "river" , "小河"}) );
	set_weight(500);
	set_max_encumbrance(200000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条发出鱼鳞般的光芒的小河，可以ｓｗｉｍ\n");
		set("value", 1);
	}
}
int is_container() { return 1; }
