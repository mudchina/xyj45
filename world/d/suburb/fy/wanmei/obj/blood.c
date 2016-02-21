inherit COMBINED_ITEM;
void create()
{
	set_name("°ë¸ÉµÄÑªµÎ", ({ "blood", "dry blood" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ì²");
		set("base_unit", "µÎ");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	setup();
}
