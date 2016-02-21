
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("ÎğÍüÎÒ", ({ "wu grass" , "grass"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Öê");
		set("value", 1);
	}
}



