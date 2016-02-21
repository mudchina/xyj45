// doll.c 阿甘

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name("阿甘", ({"doll"}));
	set("nickname", GRN"中场队员"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他就是著名的「阿甘」。金庸群侠传的自动启动程序就出自于他之手\n"
		"他还是一位狂热的球迷，曾任TMN BBS足球板的板主。\n");
	setup();

	carry_object("/d/suburb/fy/city2/obj/jinduan")->wear();
}
