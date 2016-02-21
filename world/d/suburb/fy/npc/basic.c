
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("花无缺",({"basic"}));
	set("nickname", HIM "铁掌降龙"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是大侠花无缺。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
