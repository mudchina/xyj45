
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("ÂÞÉ²ÅÆ" , ({ "luosha" , "pai"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¿é");
		set("long", "Ò»¿éÂÞÉ²ÅÆ\n");
		set("value", 100000);
	}
}



