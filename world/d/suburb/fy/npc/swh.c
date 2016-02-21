
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("水无痕",({"swh"}));
set("nickname",HIM"抽刀断水水更流" NOR);
 
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是星宿首魔「水无痕」。\n");
	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
