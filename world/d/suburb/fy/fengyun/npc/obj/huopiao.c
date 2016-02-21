
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("货票", ({ "huopiao" , "货票"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张金狮镖局的货票\n");
		set("value", 1);
	}
}



