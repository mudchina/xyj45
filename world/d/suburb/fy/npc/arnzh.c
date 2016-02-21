// arnzh.c 温火

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("温火",({"arnzh"}));
	set("nickname", HIY"观日剑"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是武当首侠「温火」。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
