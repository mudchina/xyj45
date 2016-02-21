
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("温乐",({"goose"}));
	set("nickname", HIB "老叫化"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是丐帮大侠温乐。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
