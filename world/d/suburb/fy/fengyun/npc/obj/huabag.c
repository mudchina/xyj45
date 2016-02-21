
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("花粉袋", ({ "hubag" , "花粉袋"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "气味芳香的花粉袋\n");
		set("value", 1000);
	}
}



