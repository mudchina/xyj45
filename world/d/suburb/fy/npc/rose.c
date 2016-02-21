
#include <ansi.h>

inherit NPC;

void create()
{
set_name("顾横波",({"rose"}));
	set("nickname", HIG "流" NOR+HIY "彩" NOR +HIG "红" NOR);
	set("gender", "女性");
	set("age", 20);
	set("long", 
"这就是星宿大魔女顾横波");  
  

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
