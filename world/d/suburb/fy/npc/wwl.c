
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("欣云", ({"wwl"}));
	set("nickname", HIM "我是一片云" NOR);
	set("title", "桃花岛第二代弟子");
	set("gender", "女性");
	set("age", 20);
	set("long", 
		"他就是桃花岛的才女欣云，后来被风云给骗去了。");
        setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
