// 
// 

inherit ITEM;
inherit F_LIQUID;
void create()
{
	set_name("黑瓷药瓮", ({ "medvase", "vase" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个散发着浓烈的中草药味的药瓮\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "soup",
		"name": "当归补血鱼汤",
		"remaining": 5,
		"drunk_apply": 0,
	]) );
}
