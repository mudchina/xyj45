// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("白玉小马桶", ({ "matong", "tong" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个白玉小马桶，一看就是上流人用的东西．．\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 25);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "漂着一些东西的水",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}
