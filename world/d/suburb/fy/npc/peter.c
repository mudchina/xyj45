
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("风",({"peter"}));
	set("nickname", HIC"一剑走江湖"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是当年叱诧风云的「风」大侠。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
