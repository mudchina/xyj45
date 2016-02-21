
inherit ITEM;
void create()
{
	set_name("泥人儿" , ({ "niren" , "toy"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个制作精巧的彩色泥人儿\n");
		set("value", 1000);
	}
}



