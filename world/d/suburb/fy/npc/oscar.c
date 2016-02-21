
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("苏童",({"oscar"}));
	set("nickname", HIY"乖孩子"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是乖孩子oscar。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
