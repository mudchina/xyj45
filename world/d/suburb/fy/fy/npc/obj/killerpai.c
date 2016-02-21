
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("É±ÊÖÅÆ", ({ "pai" , "É±ÊÖÅÆ"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¿é");
		set("long", HIR "ÏÊºìËÆÑªµÄÉ±ÊÖÅÆ\n" NOR);
		set("value", 1000);
	}
}



