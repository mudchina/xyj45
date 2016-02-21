
inherit ITEM;
void create()
{
	set_name("Ö½Ç®" , ({ "zhiqian" , "Ö½Ç®"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "´®");
		set("long", "Ò»´®Ö½Ç®\n");
		set("value", 1000);
	}
}



