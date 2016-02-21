// 
// 

inherit ITEM;
void create()
{
	set_name("铜人的心", ({ "heart" , "心", "铜人的心"}) );
	set_weight(500);
	set_max_encumbrance(1);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个在铜人心口，针眼大小般的一个孔。\n");
		set("value", 1);
	}
}
int is_container() { return 1; }
