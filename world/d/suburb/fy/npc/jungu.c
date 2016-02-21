// jungu.c 水灵儿

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("水灵儿", ({"jungu"}));
	set("nickname", GRN"桃花岛开山祖师"NOR);
	set("gender", "女性");
	set("age", 20);
	set("long", 
		"他就是桃花岛的创始人「水灵儿」。\n");

	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
