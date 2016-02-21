// five.c 五叶

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("五叶", ({"five"}));
	set("nickname", GRN"白驼山开山祖师"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是白驮山的创始人「五叶」。\n");
	setup();
	
	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
