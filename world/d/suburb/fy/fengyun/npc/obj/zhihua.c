
inherit ITEM;
void create()
{
	set_name("纸花" , ({ "zhihua" , "纸花"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("long", "一串纸花\n");
		set("value", 1000);
	}
}



