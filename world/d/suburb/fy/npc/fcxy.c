// arnzh.c 温火

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("温约红", ({"fcxy"}));
	set("nickname",HIR"武当鼻祖"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是负担起兴复武当大业的大巫师温约红！\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
