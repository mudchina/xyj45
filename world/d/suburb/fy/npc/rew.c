
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("藏马",({"rew"}));
	set("nickname", HIR"中原一点红"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是大侠藏马。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
