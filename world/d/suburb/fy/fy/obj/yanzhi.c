
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR "ëÙÖ¬" NOR, ({ "yanzhi" , "ëÙÖ¬"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ºĞ");
		set("long", "ÏÊºìËÆÑªµÄÉÏµÈëÙÖ¬\n");
		set("value", 1000);
	}
}



