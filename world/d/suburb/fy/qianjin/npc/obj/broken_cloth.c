
inherit ITEM;
void create()
{
	set_name("残破的女子内衣", ({ "neiyi" , "内衣"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件残破的女子内衣\n");
		set("value", 1);
	}
}



