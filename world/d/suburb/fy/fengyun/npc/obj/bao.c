
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("刨花油", ({ "bao" , "刨花油"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "樽");
		set("long", "气味芳香的刨花油\n");
		set("value", 1000);
	}
}



