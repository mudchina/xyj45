
inherit ITEM;
void create()
{
	set_name("小风车" , ({ "small toy" , "toy"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个迎风就会转的小风车\n");
		set("value", 1000);
	}
}



