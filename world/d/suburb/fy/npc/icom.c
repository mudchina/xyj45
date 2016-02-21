
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("阿康",({"icom"}));
      set("nickname",HIG "多情剑客" NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是少林首徒阿康。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
