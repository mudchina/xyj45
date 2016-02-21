// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("小金杯", ({ "gold cup", "cup" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个小小的金杯，大概装得一、两口的酒。\n");
		set("unit", "个");
		set("value", 100000);
		set("max_liquid", 2);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "黄河大曲",
		"remaining": 2,
		"drunk_apply": 20,
	]) );
}
