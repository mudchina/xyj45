
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("黄咏蝶",({"sasa"}));
	set("nickname", HIG "吸血鬼、恶赌棍" NOR);
	set("gender", "无性");
	set("age", 20);
	set("long", 
		"他就是首席公公「黄咏蝶」。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
