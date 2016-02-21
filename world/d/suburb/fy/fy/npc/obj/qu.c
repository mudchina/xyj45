
inherit ITEM;
void create()
{
	set_name("煮熟了的蛆" , ({ "qu" , "dead qu"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条白白的煮熟了的蛆\n");
		set("value", 0);
	}
}



