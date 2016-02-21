// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大酒袋", ({ "quskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "最劣的白酒",
		"remaining": 15,
		"drunk_apply": 30,
	]) );
}
