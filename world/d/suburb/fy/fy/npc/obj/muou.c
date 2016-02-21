
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("面目空白的木像", ({ "muxiang" , "木像"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "面目空白的木像\n");
		set("value", 10);
	}
}



