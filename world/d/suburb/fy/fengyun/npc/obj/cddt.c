// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青瓷大碗", ({ "dawan", "wan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个精工制作的景太蓝大碗\n");
		set("unit", "个");
		set("value", 1000);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "soup",
		"name": "成都蛋汤",
		"remaining": 5,
		"drunk_apply": 0,
	]) );
}
