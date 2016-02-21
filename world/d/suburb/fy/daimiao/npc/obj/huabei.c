// 
// 

inherit ITEM;
void create()
{
	set_name("绣龙花缎被", ({ "huabei" , "绣龙花缎被"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "床");
		set("prep", "under");
		set("value", 1);
	}
}
int is_container() { return 1; }
